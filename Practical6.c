/*6.	Create a structure containing name and telephone number.
 Write a program to sort and search this data on name or telephone number on user choice.
*/
#include <stdio.h>
#include <string.h>


struct Contact {
    char name[50];
    char phoneNumber[15];
};


int searchByName(struct Contact contacts[], int n, char key[]) {
    int i;
	for ( i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, key) == 0) {
            return i; 
        }
    }
    return -1; 
}


int searchByNumber(struct Contact contacts[], int n, char key[]) {
    int i;
	for ( i = 0; i < n; i++) {
        if (strcmp(contacts[i].phoneNumber, key) == 0) {
            return i;
        }
    }
    return -1; 
}

void sortByName(struct Contact contacts[], int n) {
    struct Contact temp;
    int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                // Swap if out of order
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
}

// Function to display the contact details
void displayContact(struct Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone Number: %s\n", contact.phoneNumber);
}

int main() {
    int n, choice;
    char key[50];

    printf("Enter the number of contacts: ");
    scanf("%d", &n);

    struct Contact contacts[n];
	int i;

    for ( i = 0; i < n; i++) {
        printf("\nEnter details for contact %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", contacts[i].name);
        printf("Phone Number: ");
        scanf("%s", contacts[i].phoneNumber);
    }
    printf("\n1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Sort by Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter name to search: ");
            scanf("%s", key);
            int index = searchByName(contacts, n, key);
            if (index != -1) {
                printf("\nContact found:\n");
                displayContact(contacts[index]);
            } else {
                printf("\nContact not found.\n");
            }
            break;

        case 2:
            printf("Enter phone number to search: ");
            scanf("%s", key);
            index = searchByNumber(contacts, n, key);
            if (index != -1) {
                printf("\nContact found:\n");
                displayContact(contacts[index]);
            } else {
                printf("\nContact not found.\n");
            }
            break;

        case 3:
            sortByName(contacts, n);
            printf("\nContacts sorted by name:\n");
            for ( i = 0; i < n; i++) {
                displayContact(contacts[i]);
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

