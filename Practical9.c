//9.	Write a program that calculates difference between two dates in days.

#include <stdio.h>

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

int dateToDays(struct Date date) {
    int days = 0;
	int i;
    for ( i = 1; i < date.year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }

    for ( i = 1; i < date.month; i++) {
        days += daysInMonth(i, date.year);
    }

    days += date.day;

    return days;
}

int differenceInDays(struct Date date1, struct Date date2) {
    return dateToDays(date2) - dateToDays(date1);
}

int main() {
    struct Date date1, date2;

    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    int difference = differenceInDays(date1, date2);

    printf("Difference between the two dates: %d days\n", difference);

    return 0;
}

