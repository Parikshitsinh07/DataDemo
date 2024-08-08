#include <stdio.h>

void printThreeDigitsInWords(int num) {
    const char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const char *teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                            "Eighteen", "Nineteen"};
    const char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", 
                          "Ninety"};

    int hundreds = num / 100;
    num %= 100;

    if (hundreds > 0) {
        printf("%s Hundred ", units[hundreds]);
    }

    if (num > 10 && num < 20) {
        printf("%s ", teens[num - 10]);
    } else {
        int tensDigit = num / 10;
        int unitsDigit = num % 10;

        if (tensDigit > 0) {
            printf("%s ", tens[tensDigit]);
        }

        if (unitsDigit > 0) {
            printf("%s ", units[unitsDigit]);
        }
    }
}

void convertFigureToWords(int figure) {
    int billion = figure / 1000000000;
    int million = (figure / 1000000) % 1000;
    int thousand = (figure / 1000) % 1000;
    int units = figure % 1000;

    if (billion > 0) {
        printThreeDigitsInWords(billion);
        printf("Billion ");
    }

    if (million > 0) {
        printThreeDigitsInWords(million);
        printf("Million ");
    }

    if (thousand > 0) {
        printThreeDigitsInWords(thousand);
        printf("Thousand ");
    }

    if (units > 0 || figure == 0) {
        printThreeDigitsInWords(units);
    }

    printf("\n");
}

int main() {
    int figure;

    printf("Enter a figure: ");
    scanf("%d", &figure);

    convertFigureToWords(figure);

    return 0;
}

