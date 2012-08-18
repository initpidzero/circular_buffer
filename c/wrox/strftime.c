/**************************************************************************/
/*****To use strftime and strptime fuctions *******************************/
/**************************************************************************/

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t the_time;
    struct tm *tm_ptr, timestruct;
    char buf[265]; /*buffer to store resulting string*/
    char *result;
    
    (void)time(&the_time);
    tm_ptr = localtime(&the_time);
    
    strftime(buf, 256, "%A %d %B, %I:%S %p", tm_ptr);
    /*buf store value from tm_ptr*/
    printf("strftime is %s\n",buf); /*see how time is used*/

    strcpy(buf,"SAT 26 July 2004, 19:05 will do fine"); 
    printf("calling strptime with %s value\n",buf);
    tm_ptr = &timestruct;

    result = strptime(buf, "%a %d %b %Y, %H:%M", tm_ptr);  
    printf("strptime consumed up to: %s\n", result);
    
    printf("strptime gives: \n");
    printf("date: %02d/%02d/%02d\n", (tm_ptr->tm_year+1900)%100,
                        tm_ptr->tm_mon+1, tm_ptr->tm_mday); 
    printf("time: %02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min); 
    
    exit(0);
}
