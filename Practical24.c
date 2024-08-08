/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-Meera Kansara
project 8 :- Singely Sorted Linked
*/

#include <stdio.h>
#include <stdlib.h>
// Creat a Struct for linked list
struct node {
    int val;
    struct node* next;
};

void insert(struct node**, int);
void display(struct node*);

int main() {
    struct node* head = NULL;
    int choice = 1;
    int values,ch;

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
                //	ch=abc(values);
            		if(scanf("%f",&ch)!= 1){
            			printf("Invalid input. Please enter a valid integer.\n");
            			while (getchar() != '\n');
            			continue;
					}
					else{
						printf("Your Floting Number Convert To Intager");
					}
       			 }
                	insert(&head, values);
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
// insert in linked list
void insert(struct node** head,int values ) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = values;
    newnode->next = NULL;
	if (*head == NULL ) {
        newnode->next = *head;
        *head = newnode;
        printf("Value inserted !\n");
    } else {
        struct node* current = *head;
        struct node* previous = NULL;
        while (current != NULL ) {
            previous = current;
            current = current->next;
        }
        previous->next = newnode;
        newnode->next = current;
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
