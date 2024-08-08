/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-Meera Kansara
*/
/*
101, "JohnDoe", "Laptop"
102, "JaneSmith", "Desktop"
103, "BobJohnson", "GamingPC"
104, "AliceWilliams", "Workstation"

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int id;
    char name[20];
    char computerType[20];
    struct Customer* next;
};

void insert(struct Customer**, int, const char[], const char[]);
void display(struct Customer*);
void Delete(struct Customer**, int);
void updates(struct Customer**, int);
int main() {
    struct Customer* head = NULL;
    int cid, choice = 1;
    char cname[20], ccomputerType[20];

    while (choice != 0) {
        printf("\n\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert\n2. Display\n3. Delete\n4. Updates\n0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Customer Id : ");
                if (scanf("%d", &cid) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                printf("Enter Customer Name: ");
                scanf("%19s", cname);  // Limit name to 19 characters
                printf("Enter computerType : ");
                scanf("%19s", ccomputerType);  // Limit department to 19 characters
                insert(&head, cid, cname, ccomputerType);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter Customer Id to delete: ");
                if (scanf("%d", &cid) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                Delete(&head, cid);
                break;
            case 4:
            	printf("Enter Customer Id to update: ");
                if (scanf("%d", &cid) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                updates(&head, cid);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}

void insert(struct Customer** head, int cid, const char cname[], const char ccomputerType[]) {
    struct Customer* newnode = (struct Customer*)malloc(sizeof(struct Customer));
    newnode->id = cid;
    strcpy(newnode->name, cname);
    strcpy(newnode->computerType, ccomputerType);
    newnode->next = NULL;
	if (*head == NULL ) {
        newnode->next = *head;
        *head = newnode;
        printf("Value inserted !\n");
    } else {
        struct Customer* current = *head;
        struct Customer* previous = NULL;
        while (current != NULL ) {
            previous = current;
            current = current->next;
        }
        previous->next = newnode;
        newnode->next = current;
        printf("Value inserted !\n");
    }
    
}


void display(struct Customer* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        printf("\nPrinting values:\n");
        while (head != NULL) {
            printf("\tCustomer Id : %d\n", head->id);
            printf("\tCustomer Name :%s\n",head->name);
            printf("\tCustomer ComputerType :%s\n\n",head->computerType);
            
            head = head->next;
        }
        printf("\n");
    }
}
void Delete(struct Customer** head, int cid) {
    struct Customer* current = *head;
    struct Customer* previous = NULL;

    while (current != NULL && current->id != cid) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in the linked list.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Value deleted successfully.\n");
}
void updates(struct Customer** head, int cid) {
    int option;
	struct Customer* current = *head;
    struct Customer* previous = NULL;

    while (current != NULL && current->id != cid) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in the linked list.\n");
        return;
    }

    	 printf("\tCustomer Id : %d\n", current->id);
         printf("\tCustomer Name :%s\n",current->name);
         printf("\tCustomer ComputerType :%s\n",current->computerType);
         printf("What you Want updates\n");
		 	printf("1.Name\n");
		 	printf("2.ComputerType\n");
		 	printf("3.Both\n");
		 	printf("Select One :");
		 	scanf("%d",&option);
		 	if(option==1){
		 		printf("Enter Your name :");
		 		scanf("%s",&current->name);
			 }
			 else if(option==2){
			 	printf("Enter ComputerType :");
		 		scanf("%s",&*current->computerType);
			 } 
			 else{
			 	printf("Enter Your name :");
		 		scanf("%s",&current->name);
		 		printf("Enter ComputerType :");
		 		scanf("%s",&*current->computerType);
			 } 
        //*head = current->next;

    //free(current);
    printf("Value updates successfully.\n");
}

