#include <stdio.h>

#define MAX_SALESMEN 50
#define MONTHS 4

struct Salesman {
    char name[50];
    float sales[MONTHS];
    float totalSales;
};

void displaySales(struct Salesman *salesmen, int numSalesmen) {
	printf("______________________________________________________________________________________________________________________\n");
	printf("%-30s %-32s %-25s %-15s\n","Salesman","Sales Of Months","TotalSales","% of Total Sales");
	printf("%-20s %-10s %-10s %-10s %-25s %-10s %-10s %-10s %-10s\n" ," ", "Jan", "Feb", "Mar", "April", "Jan", "Feb", "Mar", "April");
	printf("______________________________________________________________________________________________________________________\n\n");
	int i,j;
    for ( i = 0; i < numSalesmen; i++) {
        printf("%-20s", salesmen[i].name);

        for ( j = 0; j < MONTHS; j++) {
            printf("%-10.2f ", salesmen[i].sales[j]);
        }

        printf("%-15.2f ", salesmen[i].totalSales);

        if (salesmen[i].totalSales > 0) {
            for ( j = 0; j < MONTHS; j++) {
                printf("%-10.2f ", (salesmen[i].sales[j] / salesmen[i].totalSales) * 100);
            }
        } else {
            for ( j = 0; j < MONTHS; j++) {
                printf("%-15s ", "N/A");
            }
        }

        printf("\n");
    }
}

int main() {
    FILE *file = fopen("sales.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Salesman salesmen[MAX_SALESMEN];
    int numSalesmen = 0;
	int i;
    while (fscanf(file, "%s %f %f %f %f",
                  salesmen[numSalesmen].name,
                  &salesmen[numSalesmen].sales[0],
                  &salesmen[numSalesmen].sales[1],
                  &salesmen[numSalesmen].sales[2],
                  &salesmen[numSalesmen].sales[3]) == 5 && numSalesmen < MAX_SALESMEN) {
        // Calculate total sales for each salesman
        salesmen[numSalesmen].totalSales = 0;
        for ( i = 0; i < MONTHS; i++) {
            salesmen[numSalesmen].totalSales += salesmen[numSalesmen].sales[i];
        }

        numSalesmen++;
    }

    fclose(file);

    // Display sales in formatted manner
    displaySales(salesmen, numSalesmen);

    return 0;
}

