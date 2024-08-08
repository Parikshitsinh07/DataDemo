#include <stdio.h>

int main() {
    FILE *file = fopen("meter_readings.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int customerNo, prevReading, lastReading, customerType;
    float meterReading, billAmount;

    printf("%-15s %-15s %-15s %-15s %-15s\n", "Customer No", "Prev Reading", "Last Reading", "Customer Type", "Bill Amount");
    printf("===========================================================================\n");

    while (fscanf(file, "%d %d %d %d", &customerNo, &prevReading, &lastReading, &customerType) == 4) {
        meterReading = lastReading - prevReading;

        switch (customerType) {
            case 1:
                billAmount = meterReading * 1.50;
                break;
            case 2:
                billAmount = meterReading * 2.50;
                break;
            case 3:
                if (meterReading <= 50) {
                    billAmount = meterReading * 1.50;
                } else {
                    billAmount = 50 * 1.50 + (meterReading - 50) * 2.50;
                }
                break;
            default:
                printf("Invalid customer type for customer %d\n", customerNo);
                continue;
        }

        printf("%-15d %-15d %-15d %-15d %-15.2f\n", customerNo, prevReading, lastReading, customerType, billAmount);
    }

    fclose(file);

    return 0;
}

