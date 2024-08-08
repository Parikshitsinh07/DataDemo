#include<stdio.h>
void Insarting(int [],int *,int *);
void Deleting(int [],int *,int *);
void Trevels(int [],int,int);
void Modify(int [],int*,int*);
int max=5;
void main(){
	int Queqs[max];
	int start=-1,end=-1,option;
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
			case 4:Modify(Queqs,&start,&end);
					break;
			case 5:printf("\t Program is Exited");
					break;
			default :
				printf("Option is not Valid Please try agien \n ");
				break;
			}
		
     }while(option!=5);
}
void Insarting(int Queqs[],int *start,int *end){
	    int val;
	    if( (*end>=max-1 && *start==0 ) || (*start-*end==1) ){
				printf("Queue is Full \n");	    	
		}
		else{
				printf("Enter your pusing values:");
				scanf("%d",&val);
			if(*start==-1 && *end==-1){
				*start=*end=0;
				Queqs[*end]=val;
				printf("\n \t Values Insarted \n");
			}
			else{
				if(*end==4 && *start>0){
					*end=0;
					Queqs[*end]=val;
					printf("\n \t Values Insarted \n");
				}
				else{
					*end=*end+1;
					Queqs[*end]=val;
					printf("\n \t Values Insarted \n");
				}
			}
		}
	}
void Deleting(int Queqs[], int *start , int *end ){
	if((*start==-1 && *end==-1)){
		printf("Queue is Emtye \n");
	}
	else{
		if(*start==*end){
			printf("%d is Deleting \n",Queqs[*start]);
			*start=*end=-1;
		}
		else{
			if(*start==max-1 && *end>=0){
				printf("%d is Deleting \n",Queqs[*start]);	
				*start=0;
			}
			else{
				printf("%d is Deleting \n",Queqs[*start]);
				*start=*start+1;	
			}
		}
	}	
}
void Trevels(int Queqs[] , int start,int end){
	int i;
	if(start==-1 && end==-1){
		printf("Queue is Emtye \n");
	}
	else{
		if(start>end){
			printf("Queue is below:\n");
			printf("Start index is %d and End %d :\n",start, end);
			while(start!=end){
				if(start>=max-1){
					printf("\t %d",Queqs[start]);
					start=0;
				}
				else{
					printf("\t %d",Queqs[start]);
					start=start+1;	
				}
				if(start==end){
					printf("\t %d",Queqs[start]);
				}
			}
			printf("\n");
		}
		else{
		 	printf("Queue is below:\n");
			printf("Start index is %d and End %d :\n",start, end);
		
			for(i=start;i<=end;i++){
			printf("\t %d",Queqs[i]);
			}
			printf("\n");	
		}
		
	}	
}
void Modify(int Queqs[],int *start,int *end){
	int i,val,oldVelues;
	printf("Enter Your Old Value : ");
	scanf("%d",&oldVelues);
	printf("Enter Your New Value:");
	scanf("%d",&val);
	if(*start==-1 && *end==-1){
		printf("Queue is Emtye \n");
	}
	else{
		if(*start>*end){
			//printf("Queue is below:\n");
			//printf("Start index is %d and End %d :\n",*start, *end);
			while(*start!=*end){
				if(*start>=max-1){
					if(oldVelues==Queqs[*start]){
						printf("\t Curant Valis Is: %d \n",Queqs[*start]);
						Queqs[*start]=val;
						printf("\t Your values is Updated\n");
					}
					start=0;
				}
				else{
					if(oldVelues==Queqs[*start]){
						printf("\t Curant Valis Is: %d \n",Queqs[*start]);
						Queqs[*start]=val;
						printf("\t Your values is Updated\n");
					}
					start=start+1;	
				}
				if(*start==*end){
					if(oldVelues==Queqs[*start]){
						printf("\t Curant Valis Is: %d \n",Queqs[*start]);
						Queqs[*start]=val;
						printf("\t Your values is Updated\n");
					}
				}
			}
			printf("\n");
		}
		else{
		 	//printf("Queue is below:\n");
			//printf("Start index is %d and End %d :\n",start, end);
		
			for(i=*start;i<=*end;i++){
					if(oldVelues==Queqs[i]){
						printf("\t Curant Valis Is: %d \n",Queqs[i]);
						Queqs[*start]=val;
						printf("\t Your values is Updated\n");
					}
		       }
			printf("\n");	
		}
		
	}	
}
