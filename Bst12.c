#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
void InsertBainry(struct root**,int);
int main()
{
    int choice, data;

    while (1)
    {
        printf("\n\nSelect operations for the Binary Search Tree:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Add an element to the Binary Search Tree\n2. Display \n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to Binary Search Tree : ");
            scanf("%d", &data);
           	InsertBainry(&head,values);
            break;
     	case 2:DisplayBainry(head);
     		break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}

void InsertBainry(struct root** head , int values){
	struct root* curr;
	struct root* pre;
	struct root* newroot = (struct root*)malloc(sizeof(struct root));
	newroot->val = values;
	newroot->left = NULL;
	newroot->right = NULL;
	if(*head == NULL){
		*head = newroot;
		//printf("\tRoot is Inserted !\n");
		printf("\tRoot is Inserted in head!\n");
	}
	else{
		curr=*head;
		while(curr != NULL){
			if(curr->val > values){
				pre = curr;
				curr = curr->left; 
			}
			else{
				pre = curr;
				curr = curr->right;
			}
		}
		if(pre->val > values){
			pre->left = newroot;
			//print("\tRoot is Inserted !\n");
			printf("\tRoot is Inserted  head -> left!\n");
		}
		else{
			pre->right = newroot;
			//print("\tRoot is Inserted !\n");
			printf("\tRoot is Inserted head -> right!\n");
		}
	}
}

void DisplayBainry(struct root* head){
	struct root* lef;
	if(head != NULL){
		lef = head->left;
		DisplayBainry(lef);
		printf("\t%d",head->val);
		DisplayBainry(head->right);
	}
}
