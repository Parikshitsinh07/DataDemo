/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-Meera Kansara
*/

#include<stdio.h>
#include <stdlib.h>  // Memorry Allocation 

// Creat a Struct for Sqular linked list
struct node{
	struct node* pre;
	int val;
	struct node* next;
};
void insert(struct node**, int);
void display(struct node*);
void Delete(struct node**, int);

int main() {
    struct node* head = NULL;
    int choice = 1;
    int values;

    while (choice != 0) {
        printf("\n\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert\n2. Display\n3. Delete\n0. Exit\n");
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
                printf("Enter your value: ");
                if (scanf("%d", &values) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                insert(&head, values);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the value to delete: ");
                if (scanf("%d", &values) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                Delete(&head, values);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}
// insert in Sqular linked list
void insert(struct node** head , int values){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->pre = NULL;
	newnode->val = values;
	newnode->next = NULL;
	if(*head == NULL){
		*head=newnode;
		newnode->pre=*head;
		newnode->next=*head;
		printf("Insarted");
		//printf("Insart in head");
	}
	else{
		struct node* curr = *head;
		struct node* pre = NULL;
		while(curr->next != *head && values >= curr->val){
			pre = curr;
			curr = curr->next;
		}
		if(pre==NULL && values <= curr->val){
			newnode->pre = curr->pre;
			curr->pre->next = newnode;
			newnode->next = curr;
			curr->pre = newnode;
			*head = newnode;
			printf("Insarted");
			//printf("Insart in head and head will be chang");	
		}
		else{
			if(pre != NULL && values <= curr->val){
				newnode->pre = pre;
				newnode->next=curr;
				pre->next = newnode;
				curr->pre = newnode;
				printf("Insarted");
				//printf("Insart in mid");
			}
			else{
				newnode->pre = curr;
				curr->next = newnode;
				newnode->next = *head;
				(*head)->pre = newnode;
				printf("Insarted");
				//printf("Insart in last");
			}
		}
	}
}
void display(struct node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked list is empty.\n");
    } else {
        struct node* current = head;
        printf("\nPrinting values:\n");
        do {
            printf("%d\n", current->val);
            current = current->next;
        } while (current != head);
    }
}

void Delete(struct node** head, int value) {
    if (*head == NULL) {
        printf("Circular Doubly Linked list is empty, nothing to delete.\n");
        return;
    }

    struct node* current = *head;
    struct node* toDelete = NULL;

    do {
        if (current->val == value) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (toDelete != NULL) {
        if (toDelete == *head) {
            *head = toDelete->next;  // Update head if the node to delete is the head.
        }
        toDelete->pre->next = toDelete->next;
        toDelete->next->pre = toDelete->pre;
        free(toDelete); // Deallocate memory for the node.
        printf("Deleted %d from the list.\n", value);
    } else {
        printf("%d not found in the list.\n", value);
    }
}


