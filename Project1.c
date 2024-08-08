#include<stdio.h>
#include<ctype.h>
void elementAddInArray(int [],int*,int val);
void elementSortInArray(int[],int*);
int deleteElementInArray(int[],int*);
void modifyInArray(int[],int*,int,int);
void Display(int [],int);
void simpleSearch(int [] ,int,int ,int);
int binarySearch(int [],int ,int ,int );
int max=5;
int main(){
	int array[max];
	int index=-1;
	int option,values,op,x ,result;
	do{
		printf("1.Add Element In Array\n");
		printf("2.Delete Element In Array\n");
		printf("3.Modify Element In Array\n");
		printf("4.Sort Element In Array\n");
		printf("5.Array Display\n");
		printf("6.Simple Search Element In Array\n");
		printf("7.Binary Search Element In Array\n");
		printf("0.Exit this Progaram\n");
		printf("Select One Option : ");
		scanf("%d",&option);
		if(isdigit(option)!=0){
			printf("\n\t Invalid Input \n");
			break;
		}
		switch(option){
			case 0:printf("\n\t Program Exited\n");
					break;
			case 1:printf("\t Enter Your Number :");
					scanf("%d",&values);
					if(isdigit(values)!=0){
						printf("\n\t Invalid Input\n");
						break;
						}
					elementAddInArray(array,&index,values);
					break;
			case 2:deleteElementInArray(array,&index);
					break;
			case 3:printf("\n\n1.Modify Array Using Index\n2.Modify Array Using Value\n Select One Option :");
					scanf("%d",&op);
					if(isdigit(op)!=0){
						printf("\n\t Invalid Input\n");
						break;
						}
					if(op==1){
						printf("Enetr Your index Number:");
						scanf("%d",&op);
						printf("Enetr Your New Value:");
						scanf("%d",&values);
						modifyInArray(array,&index,values,op);
					}
					else{
						printf("Enetr Your Value for Searchin arry :");
						scanf("%d",&op);
						printf("Enetr Your New Value :");
						scanf("%d",&values);
						modifyInArray(array,&index,values,op);
					}
					break;
			case 4:elementSortInArray(array,&index);
					break;
			case 5:Display(array,index);
				 break;
			case 6:printf("\n\n1.Searching Using Index\n2.Searching Using Value\n Select One Option :");
					scanf("%d",&op);
					if(isdigit(op)!=0){
						printf("\n\t Invalid Input\n");
						break;
						}
					if(op==1){
						printf("Enetr Your index Number:");
						scanf("%d",&values);
						simpleSearch(array,index,op,values);
					}
					else{
						printf("Enetr Your Value for Searchin arry :");
						scanf("%d",&values);
						simpleSearch(array,index,op,values);
					}
					break;
			case 7: printf("Enter your Number To Find in Array :");
					scanf("%d",&x);
					if(isdigit(x)!=0){
						printf("\n\t Invalid Input");
						break;
						}
					result = binarySearch(array, 0, max-1, x);
    				(result == -1) ? printf("\n\t Element is not present"
                           			 " in array\n")
                   					: printf("\n\t Element is present at "
                            			"index %d \n",
                            			result);
                    break;
			default:
				("\n\t Please Select a Valid Option\n");
		}
	}while(option!=0);
}
void elementAddInArray(int array[],int *index,int val){
	if(*index>=max-1){
		printf("\n\n\t Array is Full\n\n");
	}
	else{
		*index+=1;
		array[*index]=val;
		if(*index==max-1){
			printf("\n\t This Values Add In Max Index In Arry \n\t Now Arry is Full\n\n");
		}
		else{
			printf("\n\t Values is Add in Arry\n\n");	
		}
		
	}
}
void Display(int array[],int index){
			int i;
			for(i=0;i<=index;i++){
			printf("\t %d",array[i]);
		}
		printf("\n");
}
void elementSortInArray(int array[],int *index){
	int temp=0,i,j;
	if(*index==-1){
		printf("\t Arry Is Empty\n");
	}
	else{
		for (i=0;i<=*index;i++){
			for(j=0;j<=*index;j++){
				if(array[i]<array[j]){
					temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
			}
		}
		for(i=0;i<=*index;i++){
			printf("\t %d",array[i]);
		}
		printf("\n");
	}
}
int deleteElementInArray(int array[],int *index){
	int del;
	if(*index<=-1){
		printf("\t Arry Is Empty\n");
		return;
	}
	else{
		del=array[*index];
		*index=*index-1;
		if(*index == -1){
			printf("\n\t %d Values Deleted In last Index In Arry\n\t Now Arry is Empty\n\n",del);
		}
		else{
			printf("\n\t This %d Values Deleted \n",del);
		}
		return ;
	}
}
void modifyInArray(int array[],int *index,int values ,int op){
		int i;
		if(*index<=-1){
		printf("\t Arry Is Empty\n");
		}
		else{
			for(i=0;i<*index;i++){
				if(array[i]==op){
					array[i]=values;
					printf("Values is Modify\n");
				}
				else if(i==op){
					array[i]=values;
					printf("Values is Modify\n");
				}
			}
			
		}
}

int binarySearch(int array[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (array[m] == x)
            return m;
 
        if (array[m] < x)
            l = m + 1;
 	   else
            r = m - 1;
    }
    return -1;
}
void simpleSearch(int array[],int index,int op,int val){
	int i,count=0;
		if(index<=-1){
		printf("\t Arry Is Empty\n");
		}
		else{
			if(op==1){
				if(val>index){
				   printf("\n\tThis Index Is Not Valid\n");
				   return;
				}
				printf("\n\tGiven Index Of %d values Is %d \n",val,array[val]);
			}
			else{
				for(i=0;i<=index;i++){
				if(array[i]==val){
					printf("\n\tElement is present at index %d \n" ,i);
					count=1;
					}
				}
				if(count==0){
					printf("\n\tElement is not present at index  \n");
				}
			}
		}
}

