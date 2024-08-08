#include<stdio.h>
void Insarting(int [],int *,int *,int [],int *,int *,int);
void Deleting(int [],int *,int *,int [],int *,int *);
void Trevels(int [],int,int,int [],int,int);
// this program for ar you alegibal for voting or note 
void main(){
	int max=5;
	int Q1[max],Q2[max];
	int start1=-1,start2=-1,end1=-1,end2=-1,option;
	do{
		printf("1.Insarting \n");
		printf("2.Deleting \n");
		printf("3.trevels \n");
		printf("4.Exit \n");
		printf("Chocise Your one Option :");
		scanf("%d",&option);
		
		switch(option){
			case 1:Insarting(Q1,&start1,&end1,Q2,&start2,&end2,max);
					break;
			case 2:Deleting(Q1,&start1,&end1,Q2,&start2,&end2);
					break;
			case 3:Trevels(Q1,start1,end1,Q2,start2,end2);
					break;
			case 4:printf("Program is Exited");
					break;
			default :
				printf("Option is not Valid Please try agien \n ");
				break;
			}
		
     }while(option!=4);
}
void Insarting(int Q1[],int *start1,int *end1,int Q2[],int *start2,int *end2,int max){
	    int val;
	    //first Prayority if You aer age 18+
	    printf("Enter your pusing values:");
		scanf("%d",&val);
	    if(val>=18){
	    	if(*end1>=max-1){
	 		//printf("Queue is Full \n");
	 			if(*end2>=max-1){
	 			printf("Queue is Full \n");
		 			}
		 		else{
		 			if(*start2==-1 && *end2==-1){
		 				*start2=*end2=0;
		 				Q2[*end2]=val;
			 			}
			 		else{
			 			*end2=*end2+1;
			 			Q2[*end2]=val;
				 		}
		 			}
		 		}
			 else{
		 		if(*start1==-1 && *end1==-1){
		 			*start1=*end1=0;
		 			Q1[*end1]=val;
			 		}
			 	else{
			 		*end1=*end1+1;
			 		Q1[*end1]=val;
			 		}
		 		}
		}
		else{
			if(*end2>=max-1){
	 			printf("Queue is Full \n");
		 	}
		 	else{
		 		if(*start2==-1 && *end2==-1){
		 		*start2=*end2=0;
		 		Q2[*end2]=val;
			 	}
			 	else{
			 	*end2=*end2+1;
			 	Q2[*end2]=val;
				 }
		 	}	
		}
	 	
}
void Deleting(int Q1[], int *start1 , int *end1,int Q2[], int *start2, int *end2 ){
	if(*start2==-1 && *end2==-1){
		printf("Queue is Emtye \n");
		}
	else{
		if(*start1!=-1 && *end1!=-1){
				if(*start1==*end1){
					printf("%d is Deleting \n",Q1[*start1]);
					*start1=*end1=-1;
				}
				else{
					printf("%d is Deleting \n",Q1[*start1]);
					*start1=*start1+1;
					}	
			}
		else{
			if(*start2==*end2){
				printf("%d is Deleting \n",Q2[*start2]);
				*start2=*end2=-1;
			}
			else{
				printf("%d is Deleting \n",Q2[*start2]);
				*start2=*start2+1;
			}
		}
	}
}
void Trevels(int Q1[] , int start1,int end1,int Q2[] , int start2,int end2){
	int i;
	
	if(start1==-1 && end1==-1){
		printf("Queue 1 is Emtye \n");
	}
	else{
		
		printf("Queue is below:\n");
		printf("Start index is %d and End %d :\n",start1, end1);
		for(i=start1;i<=end1;i++){
			printf("\t %d",Q1[i]);
		}
		printf("\n");
	}
	if(start2==-1 && end2==-1){
		printf("Queue 2 is Emtye \n");
	}
	else{
		
		printf("Queue is below:\n");
		printf("Start index is %d and End %d :\n",start2, end2);
		for(i=start2;i<=end2;i++){
			printf("\t %d",Q2[i]);
		}
		printf("\n");
	}	
}
