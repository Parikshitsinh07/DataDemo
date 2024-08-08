#include<stdio.h>
void push(char [],int * ,char);
char pop(char [],int *);
int pre(char);
int main(){
	char ch,sop,stack[10];
	int top=-1;
	printf("Enter expression end with $ : ");
	do{
		scanf("%c",&ch);
		//a+b*c-d$
		if(ch >= 'a' && ch < 'z' && ch >='0' && ch <= '9'){
			printf("%c",ch);
		}
		else{
			if(top==-1){
				push(stack,&top,ch);
			}
			else if(ch == '(')
			{
				push(stack,&top,ch);
			}
			else if(ch == ')')
			{
				printf("%c",pop(stack,&top));
			
				while (stack[top] != '(')
				{
					sop = pop(stack,&top);
					printf("%c",sop);
				}
				pop(stack,&top);	
			}
			else{
				if(ch!='$'){
				while(pre(stack[top]) >= pre(ch)){
					//printf("opint ch");
					sop= pop(stack,&top);
					printf("%c",sop);
				}
				push(stack,&top,ch);	
				}
			}
		}
		if(ch == '$'){
				while (top != -1)
			{
				//printf("opint $");
				sop = pop(stack,&top);
				printf("%c",sop);
				
			}
		}
	}while(ch != '$');
}
void push(char stack[],int *top,char ch){
	if (*top>=4){
		printf("\t stack is full \n");
	}
	else{
		*top=*top+1;
		stack[*top]=ch;
		//printf("%c is Pushed \n",stack[*top]);
	}
}
char pop(char stack[],int *top){
	char c;
	if(*top<=-1){
		printf("\t Stack is emty \n");
		return;
	}
	else{
		//printf("\t %d is Pop \n",stack[*top]);
		c=stack[*top];
		--*top;
		return c;
	}
}
int pre( char op){
	switch(op){
		case '(':return (0);
				break;
		case ')':return (0);
				break;
		case '+':return (1);
				break;
		case '-':return (1);
				break;
		case '*':return (2);
				break;
		case '/':return (2);
		 		break;
		default: break;
	}
	}
