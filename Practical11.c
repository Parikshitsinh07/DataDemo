// 11.	Write a program that input birthday of a person and finds out age of the person in years, months and days as on today.


#include <stdio.h>
#include <time.h>

struct Date {
    int day, month, year;
};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return days[month];
    }
}

void getCurrentDate(struct Date *currentDate) {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    currentDate->day = today->tm_mday;
    currentDate->month = today->tm_mon + 1; // tm_mon is zero-based
    currentDate->year = today->tm_year + 1900; // tm_year is years since 1900
}

void calculateAge(struct Date birthdate, struct Date currentDate, int *years, int *months, int *days) {
    if (birthdate.day > currentDate.day) {
        currentDate.month -= 1;
        currentDate.day += daysInMonth(birthdate.month, currentDate.year);
    }

    if (birthdate.month > currentDate.month) {
        currentDate.year -= 1;
        currentDate.month += 12;
    }

    *years = currentDate.year - birthdate.year;
    *months = currentDate.month - birthdate.month;
    *days = currentDate.day - birthdate.day;
}

int main() {
    struct Date birthdate, currentDate;
    int years, months, days;

    printf("Enter your birthdate (dd mm yyyy): ");
    scanf("%d %d %d", &birthdate.day, &birthdate.month, &birthdate.year);

    getCurrentDate(&currentDate);

    calculateAge(birthdate, currentDate, &years, &months, &days);

    printf("Your age is: %d years, %d months, and %d days.\n", years, months, days);

    return 0;
}

