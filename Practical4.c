//4.	Write a program that concates two string without using inbuilt function.
#include <stdio.h>

void myConcat(char str1[], char str2[], char result[]) {
    int i, j;

    
    for (i = 0; str1[i] != '\0'; ++i) {
        result[i] = str1[i];
    }

   
    for (j = 0; str2[j] != '\0'; ++j) {
        result[i + j] = str2[j];
    }

    result[i + j] = '\0';
}

int main() {
    char str1[50], str2[50], result[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    myConcat(str1, str2, result);

    printf("Concatenated string: %s\n", result);

    return 0;
}

