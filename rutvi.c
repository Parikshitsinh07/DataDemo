#include<stdio.h>
int main(){
	int array[10];
	int i;
	for(i=0;i<10;i++){
		printf("Enter Your %d Number:",i+1);
		scanf("%d",&array[i]);
	}
	printf("\tindex\tvalues\n");
	for(i=0;i<10;i++){
		printf("\t%d \t%d\n",i,array[i]);
		
	}
	return 0;
}
