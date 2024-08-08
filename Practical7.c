/*7.	Write a program that converts date into words.
            Ex.  Input : 22-11-2000         Output : 22nd November, 2000
*/

#include <stdio.h>
#include <string.h>

void printDateInWords(int day, int month, int year) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};

    printf("%d", day);

    if (day >= 10 && day <= 20) {
        printf("th");
    } else {
        switch (day % 10) {
            case 1:
                printf("st");
                break;
            case 2:
                printf("nd");
                break;
            case 3:
                printf("rd");
                break;
            default:
                printf("th");
        }
    }

    printf(" %s, %d\n", months[month - 1], year);
}

int main() {
    int day, month, year,i;
    int Month[]={2,4,6,9,11};

    printf("Enter date in dd-mm-yyyy format: ");
    scanf("%d-%d-%d", &day, &month, &year);
	if((day<1 || day>31 )||( month<1 || month >12) || (day>29 && (month==2))){
		printf("Invalid Date !");
		return;
	}
	for(i=0;i<5;i++){
		if(day>30 &&(month == Month[i])){
			printf("Invalid Date !");
			return;
		}
	}
		printDateInWords(day, month, year);
    
    return 0;
}

