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
//	printf("Grade: %5.2lf\n", grade);
	return grade;

}
