/*
Author: A Bleach
Date: 04/01/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int countCharsInString(char stringToCount[]);
char* joinTwoStrings(char string1[], char string2[], char concatenatedString[]);
bool areStringsEqual(char string1[], char string2[]);
char* reverseString( char stringToReverse[], char reversedString[] );
char* reverseStringFromKeyboard( char reversedString[] );
void bubbleSort();

int main ()
{
    bubbleSort();

    char sampleString[] = {"gerbil"};
    char sampleString2[] = {"tabulature"};

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
    scanf("%s",stringToReverse);
    printf("reversed string: %s\n", reverseString(stringToReverse,reversedString));
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

void bubbleSort() {

    int itemCount = 0;
    char tempWord[20];
    char words[10][20];

    printf("\nBubble Sort\n");
    printf("===========\n");
    printf("How many words do you wish to sort?: ");
    scanf("%d",&itemCount);

    for ( int i = 0; i<itemCount; i++ ) {
        printf("Enter word %d: ",i);
        scanf("%s:",words[i]);
    }

    int nextItem = 0;
    for ( int i=0; i<itemCount-1; i++ ) { // consider moving each item...
        int innerLoopLimit = itemCount - 1 - i; // last item is now in correct position so don't compare again
        for ( int j=0; j<innerLoopLimit; j++ ) { // ...by comparing with each of the others
            nextItem = j+1;
            if ( nextItem < itemCount && strcmp(words[j], words[nextItem])>0 ) {
                strcpy(tempWord, words[nextItem]);
                strcpy(words[nextItem], words[j]);
                strcpy(words[j], tempWord);
            }
        }
    }

    printf("\nSorted list:\n");
    for ( int i=0; i<itemCount; i++ ) {
        printf("%d: %s\n",i,words[i]);
    }

    return;

}