//2.	Write a program that counts number of lines, words and characters from an input string.

#include <stdio.h>
#include <string.h>

//#define MAX_STRING_SIZE 1000

void countLinesWordsChars(const char *inputString, int *lineCount, int *wordCount, int *charCount) {
    *lineCount = 0;
    *wordCount = 0;
    *charCount = 0;

    int isWord = 0;
	int i;
    
    for ( i = 0; inputString[i] != '\0'; i++) {
        (*charCount)++;

        
        if (inputString[i] == '\n') {
            (*lineCount)++;
            isWord = 0; 
        }
 // Check for space, tab, or newline to count words
        if (inputString[i] == ' ' || inputString[i] == '\t' || inputString[i] == '\n') {
            isWord = 0;
        } 
        else if (!isWord) {
            isWord = 1;
            (*wordCount)++;
        }
    }
}

int main() {
    char inputString[1000];

    printf("Enter a string :\n");

    
    while (fgets(inputString, 1000, stdin) != NULL) {
        int lineCount, wordCount, charCount;

        
        inputString[strcspn(inputString, "\n")] = '\0';
        countLinesWordsChars(inputString, &lineCount, &wordCount, &charCount);

        printf("Lines: %d\n", lineCount);
        printf("Words: %d\n", wordCount);
        printf("Characters: %d\n", charCount);

        printf("\nEnter another string :\n");
    }

    return 0;
}

