//10.	Write a program that validates input date.

#include <stdio.h>

struct Date {
    int day, month, year;
};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int isValidDate(struct Date date) {
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
        return 0; // Invalid date
    }

    int maxDays = 31; // Assume the maximum number of days in a month

    switch (date.month) {
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
        case 2:
            maxDays = isLeapYear(date.year) ? 29 : 28;
            break;
    }

    return date.day <= maxDays;
}

int main() {
    struct Date inputDate;
    int option;
	do{
		printf("1.ceak Date \n0.exit \n select one:");
		scanf("%d",&option);
		if(option==1){
			printf("Enter a date (dd mm yyyy): ");
    		scanf("%d %d %d", &inputDate.day, &inputDate.month, &inputDate.year);

    		if (isValidDate(inputDate)) {
        	printf("The entered date is valid.\n");
   			 } else {
        		printf("Invalid date. Please enter a valid date.\n");
    		}
		}
	}while(option!=0);

    return 0;
}

