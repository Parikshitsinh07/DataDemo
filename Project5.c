#include<stdio.h>
void Insarting(int [],int *,int *);
void Deleting(int [],int *,int *);
void Trevels(int [],int,int);
void Modify (int [],int *);
void main(){
	int Queqs[5];
	int start=-1,end=-1,option,op,val;
	do{
		printf("1.Insarting \n");
		printf("2.Deleting \n");
		printf("3.trevels \n");
		printf("4.Modify \n");
		printf("5.Exit \n");
		printf("Chocise Your one Option :");
		scanf("%d",&option);
		
		switch(option){
			case 1:Insarting(Queqs,&start,&end);
					break;
			case 2:Deleting(Queqs,&start,&end);
					break;
			case 3:Trevels(Queqs,start,end);
					break;
			case 4:Modify(Queqs,&end);
					break;
			case 5:printf("\t Program is Exited");
					break;
			default :
				printf("\t Option is not Valid Please try agien \n ");
				break;
			}
		
     }while(option!=5);
}
void Insarting(int Queqs[],int *start,int *end){
	    int val;
	 	if(*end>=4){
	 		printf("\t Queue is Full \n");
		 }
		 else{
		 		printf("\t Enter your pusing values:");
				scanf("%d",&val);
		 	if(*start==-1 && *end==-1){
		 		*start=*end=0;
		 		Queqs[*end]=val;
		 		printf("\t Value Is Insarted \n");
			 }
			 else{
			 	*end=*end+1;
			 	Queqs[*end]=val;
			 	printf("\t Value Is Insarted \n");
			 }
		 }
}
void Deleting(int Queqs[], int *start , int *end ){
	if(*start==-1 && *end==-1){
		printf("\t Queue is Emtye \n");
	}
	else{
		if(*start==*end){
			printf("\t %d is Deleting \n",Queqs[*start]);
			*start=*end=-1;
		}
		else{
			printf("\t %d is Deleting \n",Queqs[*start]);
			*start=*start+1;
		}
	}	
}
void Trevels(int Queqs[] , int start,int end){
	int i;
	if(start==-1 && end==-1){
		printf("\t Queue is Emtye \n");
	}
	else{
		printf("\t Queue is below:\n");
		printf("\t Start index is %d and End %d :\n",start, end);
		for(i=start;i<=end;i++){
			printf("\t %d",Queqs[i]);
		}
		printf("\n");
	}	
}
void Modify(int Queqs[] ,int *index ){
	int val;
	printf("\t Curant Valis Is : %d\n ",Queqs[*index]);
	printf("\t Enetr Your New Values :");
	scanf("%d",&val);
	Queqs[*index]=val;
	printf("\t Your values is Updated\n");
	
}
