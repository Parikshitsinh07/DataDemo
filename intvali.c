#include<stdio.h>

void main(){
	char i;
	do{
	
	printf("Enter values");
	scanf("%c",&i);
	if(i <= 47 && i >= 57){
		printf("Invalid input !");
		return;
	}
	}while(i!=0);
	
}
