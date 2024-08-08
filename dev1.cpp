#include<stdio.h>
void add(int [] ,int *,int );
void show (int [],int );
void delet(int [],int *);
int main(){
	int opt,value,index=-1;
	int array[5];
	do{
		printf("\n1.Add Element\n");
		printf("2.Delete Element\n");
		printf("3.Show Array\n");
		printf("0.Exit\n");
		printf("Seletc One Option:");
		scanf("%d",&opt);
		switch(opt){
			case 1: printf("Enter Your number:");
					scanf("%d",&value);
					add(array,&index,value);
					break;
			case 2: delet(array,&index);
			case 3:show(array,index);
					break;
			case 0:printf("THnak You !");
					break;
			default:printf("InValid Options\n");
		}			
	}while(opt != 0);
	
	
}
void add(int array[] ,int *index,int value ){
	if(*index >= 4){
		printf("Array Full");
		return;
	}
	else{
		*index = *index + 1;
		printf("\n%d index",*index);
		array[*index]= value;
		printf("\nElement Added !"); 
	}
}
void delet(int array[],int *index){
	int value;
	if(*index <= -1){
		printf("Array Empt");
		return;
	}
	else{
		 value = array[*index];
		*index = *index - 1;
		printf("\n%d Values Deleted !",value);		
	}
}
void show (int array[],int index){
	int i ;
	if(index < 0){
		printf("Array is Emty");
	}
	else{
		printf("Stack\n");
		for (i = index ; i >= 0  ;i--){
		printf("%d\t\n",array[i]);
		}
		printf("\nQueue\n");
		for (i= 0;i <= index ;i++){
		printf("%d\t",array[i]);
		}
	}
	
}
