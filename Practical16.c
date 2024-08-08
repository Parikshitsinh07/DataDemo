#include <stdio.h>
#include <string.h>

int romanToDecimal(char romanNumeral[]) {
    int decimalNum = 0;
	int i;
    for (i = 0; i < strlen(romanNumeral); i++) {
        switch (romanNumeral[i]) {
            case 'I':
                if (romanNumeral[i + 1] == 'V' || romanNumeral[i + 1] == 'X') {
                    decimalNum -= 1;
                } else {
                    decimalNum += 1;
                }
                break;
            case 'V':
                decimalNum += 5;
                break;
            case 'X':
                if (romanNumeral[i + 1] == 'L' || romanNumeral[i + 1] == 'C') {
                    decimalNum -= 10;
                } else {
                    decimalNum += 10;
                }
                break;
            case 'L':
                decimalNum += 50;
                break;
            case 'C':
                if (romanNumeral[i + 1] == 'D' || romanNumeral[i + 1] == 'M') {
                    decimalNum -= 100;
                } else {
                    decimalNum += 100;
                }
                break;
            case 'D':
                decimalNum += 500;
                break;
            case 'M':
                decimalNum += 1000;
                break;
            default:
                printf("Invalid Roman numeral.\n");
                return -1; // Return -1 for an error
        }
    }

    return decimalNum;
}

int main() {
    char romanNumeral[20];

    printf("Enter a Roman numeral: ");
    scanf("%s", romanNumeral);

    int decimalNum = romanToDecimal(romanNumeral);

    if (decimalNum != -1) {
        printf("Decimal equivalent: %d\n", decimalNum);
    }

    return 0;
}

