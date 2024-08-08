#include<stdio.h>
#include<stdlib.h>
struct node {
	int val;
	struct node *next;
};
struct node *head=NULL;
void insart(struct node*,int );
void travels(struct node*);
int main(){
	struct node *curr = NULL;
	int option,val;
	do{
		printf("1.Insarting In List\n");
		printf("2.Deletion In List\n");
		printf("3.Travels In List\n");
		scanf("%d",&option);
		switch(option){
			case 1:printf("Enter Your number ");
					scanf("%d",&val);
					insart(curr,val);
					break;
			case 3:travels(curr);
					break;
			default:break;
		}
	}while(option!=0);	
}
void insart(struct node *curr,int values ){
	struct node *newnode;
	
	newnode = (struct node*)malloc(sizeof(struct node*));
	if(head == NULL){
		
		newnode->val=values;
		newnode->next=curr;
		head=newnode;
		curr=newnode;
		printf("\tValues insarted!\n");
	}
	else{
		printf("sorry\n");
		newnode->val=values;
		newnode->next=NULL;
		
		
		//newnode->next=curr->next;
	  	curr->next=newnode;
	    //curr=newnode;
	    
		printf("Thenku\n");
	}
}
void travels(struct node *curr){
	struct node *temp=head;
	struct node *pre;
	if(temp==NULL){
		printf("Link Is Empty\n");
	}
	else{
		while(temp!=NULL){
		pre=temp;
		printf("\t%d",pre->val);
		temp=temp->next;
		}
		printf("\n");
	}	
}
