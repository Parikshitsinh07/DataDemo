//5.	Write a program that compares two string without using inbuilt function.

#include <stdio.h>

int myStrCompare(char str1[], char str2[]) {
    int i = 0;

    
    while (str1[i] != '\0' && str2[i] != '\0') {
       
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
       
        ++i;
    }

   
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;  // Strings are equal
    } else if (str1[i] == '\0') {
        return -1; 
    } else {
        return 1; 
    }
}

int main() {
    char str1[50], str2[50];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int result = myStrCompare(str1, str2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("First string is smaller than the second string.\n");
    } else {
        printf("First string is larger than the second string.\n");
    }

    return 0;
}

