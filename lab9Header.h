#ifndef LAB9HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

/*
 * Location:	Temple University Computer Science
 * Programmer:	Braeden Trautz
 * Class:	Introduction to C Programming 1057 Fall 2018 Section 005
 * Assignment: 	Lab 9 - HEADER FILE
 * Date:	28 November 2018
 * Version:	3
 * Description: A header file that increases abstraction levels for me in lab9.
 */

void printStartupBanner( void );

#define PRIME_PROGRAMMER "Braeden Trautz"
#define TITLE "File Concatenator"
#define DESCRIPTION "This program will add together the names.txt and omr.txt files in a cohesive way"

/*
 * Function:	printStartupBanner ( void )
 * Programmer: 	Braeden Trautz
 * Date:	10 October 2018
 * Inputs:	* None *
 * Outputs: 	Prints - program description, date compiled, and programmer name, along with info sheet.
 * Globals:	PRIME_PROGRAMMER - programmer's name
 *		__DATE__	 - date compiled
 *		TITLE		 - title of the program
 *		DESCRIPTION	 - description of program
 * Returns:	* None *
 * Description: Prints out a the programmer's name, the date compiled, and then program title and description.
 */
void printStartupBanner(void)
{

	printf(BOLDWHITE"This program written by %s and compiled on %s\n\n", PRIME_PROGRAMMER, __DATE__);
	printf("%s\n",TITLE);
	printf("%s\n\n",DESCRIPTION RESET);

}

#endif // LAB9HEADER_H
