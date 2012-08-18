/* ********************************************************************** */
/* **********           This a cd database huge program        ********** */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>

#define MAX_STRING 80 /* longest response allowed */
#define MAX_ENTRY 1024 /* longest data base entry allowed */

#define MESSAGE_LINE 6 /* Misc message on this line */
#define ERROR_LINE 22 /* line to use for errors */
#define Q_LINE 20 /* line for the question */
#define PROMPT_LINE 18 /* line for prompting */

/* these macros are used by the update_cd functions */
#define BOXED_LINES 11
#define BOXED_ROWS 60
#define BOX_LINE_POS 8
#define BOX_ROW_POS 2
 
static char current_cd[MAX_STRING] = "\0";
static char current_cat[MAX_STRING];

/* file name for data base*/
const char *title_file = "title.cdb";
const char *tracks_file = "tracks.cdb";
const char *temp_file = "cdb.tmp";

void clear_all_screen(void);
void get_return(void);
int get_confirm(void);
int get_choice(char *greet, char *choices[]);
void draw_menu(char *options[], int highlight, int start_row, int start_col);
void insert_title(char *cdtitle);
void get_string(char *string);
void add_record(void);
void count_cds(void);
void find_cd(void);
void list_tracks(void);
void remove_tracks(void);
void remove_cd(void);
void update_cd(void);

/* this is data base for menus */
char *main_menu[] = 
{
   "add new CD",
   "find CD",
   "count CDs and tracks in the catalog",
   "quit",
   0,
};

char *extended_menu[] =
{
   "add new CD",
   "find CD",   
   "count CDs and tracks in the catalog",
   "list tracks on current CD",
   "remove current CD",
   "update track information",
   "quit",
   0,

};

int main(void)
{
   int choice;

   initscr();
   do  {
       choice = get_choice("Options:", 
                          current_cd[0] ? extended_menu : main_menu) ;
       switch(choice)  {
           case 'q' :
               break;
           case 'a' :
               add_record();
               break;
           case 'c' :
               count_cds();
               break;
           case 'f' :
               find_cd();
               break;
           case 'l' :
               list_tracks();
               break;   
           case 'r' :
               remove_cd();
               break;   
           case 'u' :
               update_cd();
               break;   
       }
   }while(choice != 'q');

   endwin();
   exit(EXIT_SUCCESS);
}

int get_choice(char *greet, char *choices[])
{
   static int selected_row = 0;
   int max_row = 0;
   int start_screenrow = MESSAGE_LINE, start_screencol = 10;
   char **option;
   int selected;
   int key = 0;

   option = choices;
   while(*option)  {
       max_row++;
       option++;
   }
   /* protect against menu getting shorter when CD deleted */
   if (selected_row >= max_row)
       selected_row = 0;
   clear_all_screen(); /* note this call */
   mvprintw(start_screenrow - 2, start_screencol, greet);
   keypad(stdscr, TRUE);
   cbreak(); /* cooked mode off */
   noecho();
   key = 0;
   
   while(key != 'q' && key != KEY_ENTER && key != '\n')  {
       if(key == KEY_UP)  {
           if(selected_row == 0)
               selected_row = max_row - 1;
           else
               selected_row--;
       }
       if(key == KEY_DOWN) {
           if(selected_row == (max_row - 1))
               selected_row = 0;
           else
               selected_row++;
       }
       selected = *choices[selected_row];
       /* see this call*/
       draw_menu(choices, selected_row, start_screenrow, start_screencol);  
       key = getch();
   }
 
   keypad(stdscr, FALSE);
   nocbreak();
   echo();
   if(key == 'q')
       selected = 'q';
 
   return(selected);
}
void draw_menu(char *options[], int current_highlight, 
                          int start_row, int start_col)
{
   int current_row = 0;
   char **option_ptr;
   char *txt_ptr;
   option_ptr = options;
   while(*option_ptr)  {
       if(current_row == current_highlight) attron(A_STANDOUT);
       txt_ptr = options[current_row];
       txt_ptr++;
       mvprintw(start_row + current_row, start_col, "%s", txt_ptr);
       if(current_row == current_highlight) attroff(A_STANDOUT);
       current_row++;
       option_ptr++;
   }
   
   mvprintw(start_row + current_row + 3, start_col, 
            "Move highlight then press Return");
   refresh();
}

/* clears the screen and rewrites the title and displays the information */
void clear_all_screen()
{
   clear();
   mvprintw(2, 20, "%s", "CD Database Application");
   if(current_cd[0]) 
       mvprintw(ERROR_LINE, 0, "Current CD: %s: \n", current_cat, current_cd);
   
   refresh();
}

/* this one is to add record to cd data base*/
void add_record()
{
   char catalog_number[MAX_STRING];
   char cd_title[MAX_STRING];
   char cd_type[MAX_STRING];
   char cd_artist[MAX_STRING];
   char cd_entry[MAX_STRING];
   int screenrow = MESSAGE_LINE;
   int screencol = 10;
 
   clear_all_screen();
   
   mvprintw(screenrow, screencol, "Enter new CD details");
   screenrow+= 2;
    
   mvprintw(screenrow, screencol, "Catalog Number:");
   get_string(catalog_number);/* see this function is being called */
   screenrow++;

   mvprintw(screenrow, screencol, "CD title:");
   get_string(cd_title);
   screenrow++;

   mvprintw(screenrow, screencol, "CD type:");
   get_string(cd_type);
   screenrow++;

   mvprintw(screenrow, screencol, "Artist:");
   get_string(cd_artist);
   screenrow++;
   
   mvprintw(PROMPT_LINE - 2, 5, "About to add this new entry:");
   sprintf(cd_entry, "%s, %s, %s %s", catalog_number, cd_title, 
                      cd_type, cd_artist); 
   mvprintw(PROMPT_LINE , 5, "%s", cd_entry);
   refresh();
   move(PROMPT_LINE, 0);
   /* this is a call to another function */
   if(get_confirm())  {
   insert_title(cd_entry);/*another call to a function */
   strcpy(current_cd, cd_title);
   strcpy(current_cat, catalog_number);
   }
}

/* this will read string from present line */
void get_string(char *string)
{
   int len;
   wgetnstr(stdscr, string, MAX_STRING);
   len = strlen(string);
   if(len > 0 && string[len - 1] == '\n')
       string[len - 1] = '\0';
}

/* this is to get user confirmation and read the user */
int get_confirm()
{
   int confirmed = 0;
   char first_char;

   mvprintw(Q_LINE, 5, "Are you sure? ");
   clrtoeol();
   refresh();
 
   cbreak();
   first_char = getch();
   if(first_char == 'Y' || first_char == 'y') 
       confirmed = 1;
   nocbreak();

   if(!confirmed)  {
       mvprintw(Q_LINE, 1, "Cancelled");
       clrtoeol();
       refresh();
       sleep(1);
   }
   return confirmed;
}

/* this will add title to cd data base */
void insert_title(char *cdtitle)
{
   FILE *fp = fopen(title_file, "a");
   if(!fp) 
       mvprintw(ERROR_LINE, 0, "cannot open CD Titles Database");
   else
        fprintf(fp, "%s\n", cdtitle);
   fclose(fp);    
}

/* this function deletes the old db and writes a new one to previous */
void update_cd()
{
   FILE *tracks_fp;
   char track_name[MAX_STRING];
   int len, track = 1, screen_line = 1;
   WINDOW *box_window_ptr, *sub_window_ptr;
   
   clear_all_screen();
   mvprintw(PROMPT_LINE , 5, "Re-entering tracks for CD");
   if(!get_confirm()) 
       return;
   move(PROMPT_LINE, 0);
   clrtoeol();
   
   remove_tracks(); /* this is to remove the tracks */
   mvprintw(MESSAGE_LINE , 0, "Enter a blank line to finish");
   tracks_fp = fopen(tracks_file, "a");
   box_window_ptr = subwin(stdscr, BOXED_LINES + 2, BOXED_ROWS +2,
                     BOX_LINE_POS - 1, BOX_ROW_POS - 1);
   if(!box_window_ptr)
       return;
   box(box_window_ptr, ACS_VLINE, ACS_HLINE);
  
   sub_window_ptr = subwin(stdscr, BOXED_LINES, BOXED_ROWS,
                     BOX_LINE_POS, BOX_ROW_POS);
   
   if(!sub_window_ptr)
       return;
   scrollok(sub_window_ptr, TRUE);
   werase(sub_window_ptr);
   touchwin(stdscr);

   do  {
       mvprintw(sub_window_ptr, screen_line++, BOX_ROW_POS + 2,
                "Track %d:", track);
       clrtoeol();
       refresh();
       wgetnstr(sub_window_ptr, track_name, MAX_STRING);
       len = strlen(track_name);
       if(len > 0 && track_name[len -1] == '\n')
           track_name[len - 1] = '\0';
       if(*track_name)
           fprintf(tracks_fp, "%s, %d , %s\n", current_cat, track, track_name);
       track++;
       if(screen_line > BOXED_LINES - 1)  {
           /* time to start scrolling */
           scroll(sub_window_ptr);
           screen_line--;
       }
   } while(*track_name);
   delwin(sub_window_ptr);
   fclose(tracks_fp);
}

/* remove the cd data base */
void remove_cd()
{
 
   FILE *titles_fp, *temp_fp;
   char entry[MAX_ENTRY];
   int cat_length;
  
   if(current_cd[0] == '\0')
       return;

   clear_all_screen();
   mvprintw(PROMPT_LINE , 0, "About to remove CD %s: %s", 
           current_cat, current_cd);
   if(!get_confirm()) 
       return;
   cat_length = strlen(current_cat);

   /* copy the title file to temporary, ignoring this CD*/
   titles_fp = fopen(title_file, "r");
   temp_fp = fopen(temp_file, "w");
  
   while(fgets(entry, MAX_ENTRY, titles_fp))  {
       /* compare catalog number and copy entry if no match */
       if(strncmp(current_cat, entry, cat_length) != 0)
           fputs(entry, temp_fp);
   }
   fclose(titles_fp);
   fclose(temp_fp);
   
   /* delete the titles file and rename the temporary  file */
   unlink(title_file);
   rename(temp_file, title_file);

   /* remove the track files */
   remove_tracks();

   /* reset current CD to none */
   current_cd[0] = '\0';
}

/* this function deletes trackl from cd */
void remove_tracks()
{
   FILE *tracks_fp, *temp_fp;
   char entry[MAX_ENTRY];
   int cat_length;
  
   if(current_cd[0] == '\0')
       return;
   cat_length = strlen(current_cat);

   /* copy the title file to temporary, ignoring this CD*/
   tracks_fp = fopen(tracks_file, "r");
   if(tracks_fp == (FILE *)NULL) return;
   temp_fp = fopen(temp_file, "w");
  
   while(fgets(entry, MAX_ENTRY, tracks_fp))  {
       /* compare catalog number and copy entry if no match */
       if(strncmp(current_cat, entry, cat_length) != 0)
           fputs(entry, temp_fp);
   }
   fclose(tracks_fp);
   fclose(temp_fp);
   
   /* delete the titles file and rename the temporary  file */
   unlink(tracks_file);
   rename(temp_file, tracks_file);
}

/* scans the data base and reports */
void count_cds()
{
   FILE *titles_fp, *tracks_fp;
   char entry[MAX_ENTRY];
   int titles = 0, tracks = 0;
   
   titles_fp = fopen(title_file, "r");
   if(titles_fp)  {
       while(fgets(entry, MAX_ENTRY, titles_fp))  
           titles++;
       fclose(titles_fp);
   }
  
   tracks_fp = fopen(tracks_file, "r");
   if(tracks_fp)  {
       while(fgets(entry, MAX_ENTRY, tracks_fp))  
           tracks++;
       fclose(tracks_fp);
   }
   mvprintw(ERROR_LINE , 0, "Database contains %d titles with %d tracks", 
           titles, tracks);
   get_return();
}

/* finds the cd and sets current_cd */
void find_cd()
{
   FILE *titles_fp;
   char entry[MAX_ENTRY], match[MAX_ENTRY];
   int count = 0;
   char *found, *title, *catalog;
   
   mvprintw(Q_LINE , 0, "Enter a string to search in title");
   get_string(match);

   titles_fp = fopen(title_file, "r");
   if(titles_fp)  {
       while(fgets(entry, MAX_ENTRY, titles_fp))  {
           catalog = entry;/* skip past catalog number */
           if(found == strstr(catalog, ",")) {
               *found = '\0'; 
               title = found + 1;
               /* zap past the comma find next entry */
               if(found == strstr(title, ",")) {
                   *found = '\0';
                   if(found == strstr(title, match)) {
                       count++;
                       strcpy(current_cd, title);
                       strcpy(current_cat, catalog);
                   }
               } 
           }
       }
       fclose(titles_fp);

   }
   if(count != 1)  {
       if(count == 0)
            mvprintw(ERROR_LINE , 0, "sorry no match found");
       if(count > 1)
            mvprintw(ERROR_LINE , 0, "sorry ambigous %d cd found" , count);
        current_cd[0] = '\0';
        get_return();
   }
}

 /* list the cd's */  
void list_tracks()
{
   FILE *tracks_fp;
   char entry[MAX_ENTRY];
   int cat_length, lines_op = 0, tracks = 0, key, first_line = 0;
   WINDOW *track_pad_ptr;

  if(current_cd[0] == '\0')  {
       mvprintw(ERROR_LINE , 0, "you must select the cd first");
       get_return();
       return;
  }
  clear_all_screen();
  cat_length = strlen(current_cat);

   /* first count the no. of tracks */ 
   tracks_fp = fopen(tracks_file, "r");
   if(!tracks_fp)  
       return;
   while(fgets(entry, MAX_ENTRY, tracks_fp))  
       if(strncmp(current_cat, entry, cat_length) == 0)
           tracks++;
   fclose(tracks_fp);
   
   /* Make a new pad, ensure that even if there is only a single track  
      the pad is large enough so the later prefresh() is always valid */
   track_pad_ptr = newpad(tracks + 1 + BOXED_LINES, BOXED_ROWS + 1);
   if(!track_pad_ptr)
       return;
    
   tracks_fp = fopen(tracks_file, "r");
   if(!tracks_fp)  
       return;
   
   mvprintw(4 , 0, "CD track lisiting\n");

   /* write the track info into pad */
   while(fgets(entry, MAX_ENTRY, tracks_fp))  
       if(strncmp(current_cat, entry, cat_length) == 0)
           mvprintw(track_pad_ptr, lines_op++, 0, "%s", 
                     entry + cat_length + 1);
   fclose(tracks_fp);
   
   if(lines_op > BOXED_LINES) 
       mvprintw(MESSAGE_LINE , 0, "cursor keys to scroll q or RETURN to quit");
   else
       mvprintw(MESSAGE_LINE , 0, "q or RETURN to quit");
   wrefresh(stdscr);
   keypad(stdscr, TRUE);
   cbreak();
   noecho();
   key = 0;
   while(key != 'q' && key != KEY_ENTER && key != '\n')  {
       if(key == KEY_UP)  
           if(first_line > 0)
               first_line--;
       if(key == KEY_DOWN) 
            if(first_line + BOXED_LINES + 1 < tracks)
               first_line++;
  
       /* now draw the appropriate part of the pad on the screen */
       prefresh(track_pad_ptr, first_line, 0, BOX_LINE_POS, BOX_ROW_POS,
                BOX_LINE_POS + BOXED_LINES, BOX_ROW_POS + BOXED_ROWS);
       key = getch();
   }
   delwin(track_pad_ptr); 
   keypad(stdscr, FALSE);
   nocbreak();
   echo();
}

/* this function points for return */
void get_return()
{
   int ch;
   mvprintw(23, 0, "%s", "Press return");
   refresh();
   while((ch = getchar()) != '\n' && ch != EOF);
}
