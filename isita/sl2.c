#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

void insart(struct node**,int);
void deletion(struct node ** ,int);
void travels(struct node*);
int main(){
	struct node *head = NULL;
	
	int option,val;
	do{
		printf("\n1.Insarting In Linked List\n");
		printf("2.Deletion In Linked List\n");
		printf("3.Travels In Linked List\n");
		scanf("%d",&option);
		switch(option){
			case 1:printf("\nEnter Your number ");
					scanf("%d",&val);
					insart(&head,val);
					break;
			case 2:printf("\nEnter Your number for Delete:");
					scanf("%d",&val);
					deletion(&head,val);
					break;
			case 3:travels(head);
					break;
			default:break;
		}
	}while(option!=0);	
}
void insart(struct node** head,int values){
	struct node *newnode;
	struct node *pre;
	struct node *curr;
	struct node *pre2;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = values;
	newnode->next = NULL;
	if(*head == NULL)
	{
		*head = newnode;
		newnode->next=*head;	
	}
	else
	{
		pre= *head;
		curr=*head;
		pre2=NULL;
		do
		{	
			if(values > curr->val)
			{
				pre2=pre;
				pre = curr;
			}
			curr=curr->next;
			
		}while(curr->next != *head);
		if(pre == *head)
		{
			*head = newnode;
			newnode->next = pre;
			curr->next=newnode;
			printf("\nhead change Your number ");
		}
		else
		{
			if(pre2->next==pre)
			{
				pre2->next=newnode;
				newnode->next=pre;
				printf("\nmid change Your number ");
			}
			else
			{
				curr->next=newnode;
				newnode->next=*head;
				printf("\nlast change Your number ");
			}
		}	
	}
}
void deletion(struct node ** head , int values)
{	
	struct node* curr ;
	struct node* pre;
	int found = 0;
	if(*head == NULL)
	{
		printf("\nLink Is Empty\n");
	}
	else
	{
		pre = NULL;
		curr = *head;
		while(found == 0 && curr != NULL )
		{
			if(values == curr->val)
			{
				found = 1;
			}
			else
			{
				pre = curr;
				curr = curr->next;
			}
		}
		if(found == 0)
		{
			printf("\nVal is not present in linked list\n");
			return;	
		}
		else
		{
		
		}
	}
}
void travels(struct node *head){
	struct node *temp=head;
	if(temp==NULL){
		printf("Link Is Empty\n");
	}
	else
	{
		do{
			printf("\t%d",temp->val);
			temp=temp->next;
		}while(temp!=head);	
	}	
}
