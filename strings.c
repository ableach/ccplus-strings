/*
Author: A Bleach
Date: 04/01/2021
*/

#include <stdio.h>

int countCharsInString(char stringToCount[]);
char joinTwoStrings(char string1[], char string2[]);

int main ()
{
    char sampleString[] = {"test"};
    printf("String length = %d\n",countCharsInString(sampleString));
    return 0;
}

int countCharsInString(char stringToCount[])
{
    int stringPosition = 0;
    char charSlice;
    while ( stringToCount[stringPosition] != '\0' ) {
        stringPosition++;
    }

    return stringPosition;
}

char joinTwoStrings(char string1[], char string2[]) {
    char concatenatedString[];
    int string1Length = countCharsInString(string1);
    int string2Length = countCharsInString(string2);

    for () {

    }
    return 
}