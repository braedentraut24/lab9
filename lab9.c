// Function Comment Template:
/*
 * Function:	*
 * Programmer: 	Braeden Trautz
 * Date:	*
 * Inputs:	*
 * Outputs:	*
 * Globals:	*
 * Returns:	*
 * Description:	*
 */

#include "../include/lab9Header.h"

/*
 * Location: 	Temple University Computer Science
 * Programmer: 	Braeden Z. Trautz
 * Class: 	Introduction to C Programming 1057 Fall 2018
 * Assignment:	Lab 9 - CSV File Creator
 * Date:	27 November 2018
 * Version: 	2
 * Description:	Combines the omr.txt and names.txt files into one full data file
 */

char *findName( int a );
double findGrade( char *choices, char *key );

#define NUM_QS 11
#define NAME_LEN 50

int main ( )
{

	printStartupBanner();
	printf("Just type \"ls\" and you should see full_data.csv!\n");

	FILE *FileA = fopen("omr.txt", "r");
	FILE *Out = fopen("full_data.csv", "w");

	int id = 0;
	int i = 0;
	char choices[NUM_QS];
	char key[NUM_QS];
	char name[NAME_LEN];
	double grade;

	fscanf( FileA, "%d", &id );
	fprintf( Out, "%5.5u,", id );
	fprintf( Out, "%s,", findName( id ) );
	fscanf( FileA, "%s", key );
	for ( i = 0; i < NUM_QS; i++ )
		fprintf( Out, "%c,", key[i] );
	fprintf( Out, "100%\n" );

	while ( fscanf( FileA, "%d", &id ) == 1 ){

		fprintf( Out,"%5.5u,", id);
		fprintf( Out, "%s,", findName(id));
		fscanf( FileA, "%s", choices );
		for ( i = 0; i < NUM_QS; i++ )
			fprintf( Out, "%c,", choices[i] );
		fprintf( Out, "%3.2lf%%", findGrade(choices, key) );
		fprintf( Out, "\n" );
	}

	fclose(Out);
	return EXIT_SUCCESS;

}

/*
 * Function:	findName ( )
 * Programmer: 	Braeden Trautz
 * Date:	28 November 2018
 * Inputs:	int a		-	the id for the student you are finding the name of
 * Outputs:	* None *
 * Globals:	NAME_LEN	-	max name length
 *		NUM_QS		-	number of questions each student answers
 * Returns:	char *s		-	the concatenated string containing the first and last name of the student
 * Description: Finds the first and last names of the student associated to each ID number and returns it to main
 */
char *findName ( int a )
{

	int id, flag = 0;
	char s[NAME_LEN], s2[NAME_LEN];
	FILE *FileB = fopen("names.txt", "r");

	while ( fscanf( FileB, "%d", &id ) == 1 ){

		fscanf( FileB, "%s", &s );
		fscanf( FileB, "%s", &s2 );
		strcat( s, " " );
		strcat( s, s2 );

		if ( id == a ){

			flag = 1;
			break;

		}
	}

	return ( flag == 1 ) ? s : "Error!";

}

/*
 * Function:	findGrade ( )
 * Programmer: 	Braeden Trautz
 * Date:	28 November 2018
 * Inputs:	char *choices	-	a string of NUM_QS length containing the question answers submitted by a student
 *		char *key	-	a string of NUM_QS length containing the correct answers to all questions. a "perfect test"
 * Outputs:	* None *
 * Globals:	NUM_QS		-	the number of questions each student answers
 * Returns:	double grade	-	final grade in percentage of the student
 * Description:	Grades a student's answers in a percentage form
 */
double findGrade ( char *choices, char *key )
{

	int i;
	int numRight = NUM_QS;
	double grade = 0;

	for ( i = 0; i < NUM_QS; i++ ) {
		if ( choices[i] != key[i] )
			numRight--;
	}

	grade = (double) numRight / (double) NUM_QS;
	grade = grade * 100;

	return grade;

}
