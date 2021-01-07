/*
Author: A Bleach
Date: 04/01/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countCharsInString(char stringToCount[]);
char* joinTwoStrings(char string1[], char string2[], char concatenatedString[]);
bool areStringsEqual(char string1[], char string2[]);
char* reverseString( char stringToReverse[], char reversedString[] );
char* reverseStringFromKeyboard( char reversedString[] );

int main ()
{
    char sampleString[] = {"gerbil"};
    char sampleString2[] = {"gerbil"};

    // declare result string here so that it can be returned else we get
    // "Warning - address of stack memory associated with local variable 'concatenatedString' returned"
    // when exiting called function. This is because allocated memory for local var is released on exit 
    // as it is declared on stack local to function.
    char concatenatedString[100]; 
    char reversedString[100]; 
    
    printf("Length of %s = %d\n", sampleString, countCharsInString(sampleString));
    printf("Concatenated string = %s\n",joinTwoStrings(sampleString, sampleString2, concatenatedString));
    if ( areStringsEqual(sampleString, sampleString2) ) {
        printf("Strings %s and %s are equal\n",sampleString, sampleString2);
    } else {
        printf("Strings %s and %s are not equal\n",sampleString, sampleString2);
    }

    char stringToReverse[100];
    fgets(stringToReverse, sizeof stringToReverse, stdin);
    printf("%s\n", reverseString(stringToReverse,reversedString));
    return 0;
}

int countCharsInString(char stringToCount[])
{
    int stringPosition = 0;

    while ( stringToCount[stringPosition] != '\0' ) {
        stringPosition++;
    }

    return stringPosition;
}

char* joinTwoStrings(char string1[], char string2[], char concatenatedString[]) {
    int string1Length = countCharsInString(string1);
    int string2Length = countCharsInString(string2);

    for ( int i=0; i<string1Length; i++ ) {
        concatenatedString[i] = string1[i];
    }
    for ( int i=0; i<string2Length; i++ ) {
        concatenatedString[string1Length + i] = string2[i];
    }
    concatenatedString[string1Length + string2Length] = '\0';
    return (char*)concatenatedString;
}

bool areStringsEqual(char string1[], char string2[]) {
    bool result = true;
    int string1Length = countCharsInString(string1);
    int string2Length = countCharsInString(string2);

    if ( string1Length == string2Length ) {
        for ( int i=0; i<string1Length; i++ ) {
            if ( string1[i] != string2[i] ) {
                result = false;
                break;
            }
        }
    } else {
        result = false;
    }

    return result;
}

char* reverseString( char stringToReverse[], char reversedString[] ) {
    int stringLength = countCharsInString(stringToReverse);

    int j=stringLength-1;
    for ( int i=0; i<stringLength; i++ ) {
        reversedString[i] = stringToReverse[j--];
    }
    reversedString[stringLength+1] = '\0';

    return (char*)reversedString;

}

/*void bubbleSort() {

    for ( i=0; i<3; i++ ) {
        if () {

        }
    }

    return;

}*/