#include<stdio.h>
#include<stdlib.h>

struct root{
	struct root* left;
	int val;
	struct root* right;
};

void InsertBainry(struct root**,int);
void DisplayBainry(struct root*);
void DeleteBinary(struct root**,int);
//void preorder(struct root *);
//void inorder(struct root *);
//void postorder(struct root *);

int main(){
	struct root* head = NULL;
	int option,values;
	do{
		printf("\n\n*********Main Menu*********\n");
        printf("Choose one option from the Binary Search Tree...\n");
        printf("===============================================\n");
        printf("1. Insert\n2. Preorder Traversals\n3. Inorder Traversals\n4. Postorder Traversals\n0. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&option) != 1){
        	printf("Enter a valid Input Number");
        	while (getchar() != '\n');
        	continue;
		}
		switch(option){
			case 1:printf("Enter Your number :");
					scanf("%d",&values);
					InsertBainry(&head,values);
					break;
			case 2:DisplayBainry(head);
					break;
		
			case 3:
				    printf("Enter Your number :");
					scanf("%d",&values);
			        DeleteBinary(&head,values);
					break;
			/*case 4:postorder(head);
					break;*/
			case 0:printf("Program Will be Exit");
					break;
			default:
				printf("Please Enter a valid Option ");
		}
	}while(option!=0);
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
/*
void DisplayBainry(struct root* head){
	 if (root == NULL)
        return;

    struct TreeNode* current = root;
    struct TreeNode* stack[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }	
}*/
void DeleteBinary(struct root** head, int value) {
    int found = 0;
    struct root* curr = *head;
    struct root* parent = NULL;
    struct root* Q = NULL;
    struct root* pred = NULL;
    struct root* succ = NULL;
    char d = '\0';

    while (!found && curr != NULL) {
        parent = curr;
        if (value == curr->val) {
            found = 1;
        } else {
            if (value > curr->val) {
                curr = curr->right;
                d = 'r';
            } else {
                curr = curr->left;
                d = 'l';
            }
        }
    }

    if (!found) {
        printf("Value is not here!!\n");
        return;
    } else {
        printf("Found\n");

        if (curr->left == NULL && curr->right == NULL) {
            Q = NULL;
            printf("Case 1\n");
        } else {
            if (curr->left != NULL && curr->right != NULL) {
                pred = curr->right;
                succ = pred->left;

                while (succ->left != NULL) {
                    pred = succ;
                    succ = succ->left;
                }

                pred->left = succ->right;
                succ->left = curr->left;
                succ->right = curr->right;

                Q = succ;
                printf("Case 2\n");
            } else {
                printf("Case 3\n");

                if (curr->left == NULL) {
                    Q = curr->right;
                } else {
                    Q = curr->left;
                }
            }
        }
    }

    if (d == 'r') {
        parent->right = Q;
    } else if (d == 'l') {
        parent->left = Q;
    } else {
        *head = Q;
    }

    free(curr);
    printf("Element is deleted\n");
}


/*
void DeleteBainry(struct root** head, int values){
		struct root* curr;
		struct root* found = NULL;
		curr = *head;
		while(curr != NULL){
			if(curr->val == values){
				break;
			}
			else{
				if(curr->val > values){
					found = curr; 
					curr = curr->left;
				}
				else{
					found = curr; 
					curr = curr->right;
				}
			}
		}
		if(curr == NULL){
			printf("Value not found in the linked list.\n");
		}
		else{
			if(found == NULL){
				*head = curr->right
			}
		}
		
}

void preorder(struct root *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d ", head->val);
    preorder(head->left);
    preorder(head->right);
}


void inorder(struct root *head)
{
    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    printf("%d ", head->val);
    inorder(head->right);
}

void postorder(struct root *head)
{
    if (head == NULL)
    {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    printf("%d ", head->val);
}*/
