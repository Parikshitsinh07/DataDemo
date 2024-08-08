/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-Meera Kansara
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentInfo {
    struct studentInfo* pre;
    int roll_No;
    char name[20];
    char department[20];
    char course[10];
    struct studentInfo* next;
};

void insert(struct studentInfo**, int, const char[], const char[], const char[]);
void display(struct studentInfo*);
void Delete(struct studentInfo**, int);

int main() {
    struct studentInfo* head = NULL;
    int roll_num, choice = 1;
    char sname[20], Sdepartment[20], Scourse[10];

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
                printf("Enter your roll_num: ");
                if (scanf("%d", &roll_num) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                printf("Enter Your Name: ");
                scanf("%19s", sname);  // Limit name to 19 characters
                printf("Enter Your Department Name: ");
                scanf("%19s", Sdepartment);  // Limit department to 19 characters
                printf("Enter Your Course Name: ");
                scanf("%9s", Scourse);  // Limit course to 9 characters
                insert(&head, roll_num, sname, Sdepartment, Scourse);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the roll number to delete: ");
                if (scanf("%d", &roll_num) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    // Clear the input buffer
                    while (getchar() != '\n');
                    continue;
                }
                Delete(&head, roll_num);
                break;
            case 0:
                exit(0);
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}

void insert(struct studentInfo** head, int roll_num, const char sname[], const char Sdepartment[], const char Scourse[]) {
    struct studentInfo* newnode = (struct studentInfo*)malloc(sizeof(struct studentInfo));
    newnode->pre = NULL;
    newnode->roll_No = roll_num;
    strcpy(newnode->name, sname);
    strcpy(newnode->department, Sdepartment);
    strcpy(newnode->course, Scourse);
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        newnode->pre = *head;
        newnode->next = *head;
        printf("Inserted\n");
    }
	else{
		struct studentInfo* curr = *head;
		struct studentInfo* pre = NULL;
		while(curr->next != *head && roll_num >= curr->roll_No){
			pre = curr;
			curr = curr->next;
		}
		if(pre==NULL && roll_num <= curr->roll_No){
			newnode->pre = curr->pre;
			curr->pre->next = newnode;
			newnode->next = curr;
			curr->pre = newnode;
			*head = newnode;
			printf("Insarted");
			//printf("Insart in head and head will be chang");	
		}
		else{
			if(pre != NULL && roll_num <= curr->roll_No){
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

void display(struct studentInfo* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked list is empty.\n");
    } else {
        struct studentInfo* current = head;
        printf("\nPrinting values:\n");
        do {
            printf("\nRoll Number: %d\n", current->roll_No);
            printf("Your Name is: %s\n", current->name);
            printf("Your Course is: %s\n", current->course);
            printf("Your Department Name is: %s\n\n", current->department);
            current = current->next;
        } while (current != head);
    }
}

void Delete(struct studentInfo** head, int roll_num) {
    if (*head == NULL) {
        printf("Circular Doubly Linked list is empty, nothing to delete.\n");
        return;
    }

    struct studentInfo* current = *head;
    struct studentInfo* toDelete = NULL;

    do {
        if (current->roll_No == roll_num) {
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
        printf("Deleted %d from the list.\n", roll_num);
    } else {
        printf("%d not found in the list.\n", roll_num);
    }
}

