#include <stdio.h>
#include <stdlib.h>
// Creat a Struct for linked list
struct node {
    int val;
    struct node* next;
};

void insertBeforeNode(struct node**, int ,int);
void display(struct node*);

int main() {
    struct node* head = NULL;
    int choice = 1;
    int values,ch,beforevalues=0;

    while (choice != 0) {
        printf("\n\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert\n2. Display\n0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter your value: ");
                if (scanf("%d", &values) != 1) {
            			printf("Invalid input. Please enter a valid integer.\n");
            			while (getchar() != '\n');
            			continue;
       			 }
       			 printf("\n1.Insert Regular \n2.Insert beforevalues\nSelect One Option :");
       			 if (scanf("%d", &choice) != 1) {
            			printf("Invalid input. Please enter a valid integer.\n");
            			while (getchar() != '\n');
            			continue;
       			 }
       			 if(choice==2){
       			 		printf("Enter your  beforevalues: ");
                		if (scanf("%d", &beforevalues) != 1) {
            				printf("Invalid input. Please enter a valid integer.\n");
            				while (getchar() != '\n');
            				continue;
       					 }
					}
                insertBeforeNode(&head,beforevalues,values);
                break;
            case 2:
                display(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}
// Function to insert a new node before a specified node
void insertBeforeNode(struct node **head, int targetData, int newData) {
    struct node* current = *head;
    struct node* previous = NULL;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val= newData;
    newNode->next = NULL;
	if(*head==NULL){
		*head = newNode;
		printf("Value inserted !\n");
		return;
	}
	if(targetData==0){
		
        while (current != NULL ) {
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
        printf("Value inserted !\n");
	}
	else{
		// If the target node is the head, update the head to the new node
   		 if (current != NULL && current->val == targetData) {
        		newNode->next = current;
        		*head = newNode;
       			 return;
   			 }
   		// Traverse the list to find the node before the target node
    	while (current != NULL && current->val != targetData) {
        		previous = current;
        		current = current->next;
    		}
   		 // If the target node is not found
    	if (current == NULL) {
       		 printf("Node with data %d not found in the list.\n", targetData);
        	free(newNode); // Free the allocated memory
        	return;
    		}
    	// Insert the new node before the target node
    		previous->next = newNode;
    		newNode->next = current;
    		printf("Value inserted !\n");
	}

}
// display in linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        printf("\nPrinting values:\n");
        while (head != NULL) {
            printf("%5d ->", head->val);
            head = head->next;
        }
           printf(" NULL\n");
    }
}



