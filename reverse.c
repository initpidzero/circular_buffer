/* Author - anuz
 * Input: One String
 * Output: Reversed String
 * Two different functions used
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This function will not use any memory allocation
 */
void string_reverse1(char *string) 
{ 
	char *temp_string = string;

	while(*++temp_string) /* find the end of the string */
		; /* no statement */

	while(temp_string - string > 0) {
		char temp;
		temp = *string;
		*string++=*--temp_string;
		*temp_string = temp;
	}
}

/* This function allocates memory 
 */
char *string_reverse2(const char *string)
{
	char *new_string = (char *)malloc(strlen(string) + 1); /* please ensure this memory is free'd after use */
	if(new_string == NULL)
		return NULL;
	strcpy(new_string, string);
	string_reverse1(new_string); /* calling the other function for the actual reversal */
	return new_string;
}

/* Test program 
 */
int main (int argc, char**argv)
{
	char *string = NULL;
	char *string1 = NULL;

	if(argc == 2) {
		string1 = (char *)malloc(strlen(argv[1]) + 1);
		if(string1 == NULL) 
			return EXIT_FAILURE;
		strcpy(string1, argv[1]);
		string = argv[1];
	} else {
		fprintf(stderr, "Error: This program requires an input string for reversal\n");
		return EXIT_FAILURE;
	}

	string_reverse1(string1);
	printf("Using first function for reversal of string = %s\n", string1);

	if((string = string_reverse2(string)) == NULL) {
		if(string1 != NULL)
			free(string1);
		return EXIT_FAILURE;
	}
	printf("Using second function for reversal of string = %s\n", string);
	 	
	if(string != NULL) 
		free(string);
	if(string1 != NULL)
		free(string1);
	return EXIT_SUCCESS;
}
