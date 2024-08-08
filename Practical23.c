#include <stdio.h>

// Function to compare two strings using pointers
int compareStrings(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // Strings are not equal
        }
        str1++;
        str2++;
    }

    // Check if both strings have reached the end (i.e., are equal in length)
    return (*str1 == '\0' && *str2 == '\0');
}

int main() {
    char str1[100], str2[100];

    // Input first string
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Input second string
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Compare strings using pointers
    if (compareStrings(str1, str2)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}

