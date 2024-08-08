#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

void insart(struct node*,int);
//void deletion(struct node * ,int);
void travels(struct node);
int main(){
	struct node head ;
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
		/*	case 2:printf("\nEnter Your number for Delete:");
					scanf("%d",&val);
					deletion(&head,val);
					break;*/
			case 3:travels(head);
					break;
			default:break;
		}
	}while(option!=0);	
}

void insart(struct node *head,int values)
{
	struct node newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = values;
	newnode->next=NULL;
	if(head == NULL)
	{
		head =newnode;  
	}
	
	
}
void travels(struct node *head){
	struct node *temp=head;
	if(temp==NULL){
		printf("Link Is Empty\n");
	}
	else{
		while(temp!=NULL){
		//pre=temp;
		printf("\t %d -> ",temp->val);
		temp = temp->next;
		}
		printf("NULL\n");
	}	
}
