#include<stdio.h>
void push(int [],int *);
void peeping(int [],int);
void display(int [],int);
void pop(int [],int *);
void peep(int [],int);
void Searching(int[],int);
int max=5;
int main(){
	int stack[max],top=-1;
	int option;
	do{
		printf("1.Push \n");
		printf("2.Pop \n");
		printf("3.Peep \n");
		printf("4.Searching useing index \n");
		printf("5.Searching useing values \n");
		printf("6.Display \n");
		printf("7.Exit \n");
		printf("Chocise Your one Option :");
		scanf("%d",&option);
		if(isdigit(option)!=0){
			printf("\n\t Invalid Input\n");
			return;
				}
		switch(option){
			case 1:push(stack,&top);
					break;
			case 2:pop(stack,&top);
					break;
			case 3:peep(stack,top);
					break;
			case 4:peeping(stack,top);
					break;
			case 5:Searching(stack,top);
					break;
			case 6:display(stack,top);
					break;
			case 7:printf("Program is Exited");
					break;
			default :
				printf("Option is not Valid Please try agien \n ");
				break;
			}
		}while(option!=7);
		return 0;
	}

void push(int stack[],int *top){
	int val;
	if (*top>=max-1){
		printf("\t stack is full \n");
	}
	else{
		printf("Enter your pusing Element:");
		scanf("%d",&val);
		if(isdigit(val)!=0){
			printf("\n\t Invalid Input\n");
			return;
			}
		stack[++*top]=val;
		if(*top==max-1){
			printf("\n\t This Element Add In top In Stack \n\t Now Stack is Full\n\n");
		}
		printf("%d is Pushed \n",stack[*top]);
	}
}
void pop(int stack[],int *top){
	if(*top<=-1){
		printf("\t Stack is Empty \n");
	}
	else{
		printf("\t %d is Pop \n",stack[*top]);
		if(*top==0){
			printf("\n\t This Element Deleting In Last In Stack \n\t Now Stack is Empty\n\n");
		}
		--*top;
	}
}
void peeping(int stack[],int top){
		int val;
		printf("Enter your sreaching index :");
		scanf("%d",&val);
		if(val>=0 && val<=top){
			printf("your index values is %d \n",stack[val]);	
		}
		else{
			printf("\t Invalid Index \n");
		}
		
}
void peep(int stack[],int top){
		printf("%d this vaule is peeping \n ",stack[top]);
}
void Searching(int stack[],int top){
		int val,i,y=-1;
		printf("Enter your sreaching Value:");
		scanf("%d",&val);
		for(i=top;i>-1;i--){
			if(val==stack[i]){
				y=i;
			}
		}	
		if(y!=-1){
			printf("This vaule is avebal in Stack in %d this index \n",y);
		}
		else{
				printf("This value is not avelibal in Stack \n");
			}	
}
void display(int stack[],int top){
	int i;
	if(top<=-1){
		printf("\t Stack is Emty \n");
	}
	else{
		printf("\t index \t values \n");
		for(i=top;i>-1;i--){
			printf("\t %d \t %d\n",i,stack[i]);
		}
	}
}
