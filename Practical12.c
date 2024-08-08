//12.	Write a program that accepts age of a person in years, months and days and finds out birthdate of the person.

#include <stdio.h>
#include <time.h>

void calculateBirthdate(int years, int months, int days) {
    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Subtract the age to get the birthdate
    tm.tm_year -= years;
    tm.tm_mon -= months;
    tm.tm_mday -= days;

    // Adjust for negative values
    if (tm.tm_mon < 0) {
        tm.tm_year -= 1;
        tm.tm_mon += 12;
    }

    if (tm.tm_mday < 0) {
        tm.tm_mon -= 1;
        tm.tm_mday += 30;  // Assuming 30 days in a month for simplicity
    }

    printf("Birthdate: %02d-%02d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int main() {
    int years, months, days;

    // Input age from the user
    printf("Enter age in years, months, and days (separated by spaces): ");
    scanf("%d %d %d", &years, &months, &days);

    // Calculate and display the birthdate
    calculateBirthdate(years, months, days);

    return 0;
}

