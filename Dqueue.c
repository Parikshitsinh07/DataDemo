#include<stdio.h>
void Insarting(int [],int *,int *);
void Deleting(int [],int *,int *);
void Trevels(int [],int,int);
void Modify (int [],int *);
void main(){
	int Queqs[5];
	int start=-1,end=-1,option,op;
	do{
		printf("1.Insarting \n");
		printf("2.Deleting \n");
		printf("3.trevels \n");
	    printf("4.Modify \n");
		printf("5.Exit \n");
		scanf("%d",&option);
		
		switch(option){
			case 1:Insarting(Queqs,&start,&end);
					break;
			case 2:Deleting(Queqs,&start,&end);
					break;
			case 3:Trevels(Queqs,start,end);
					break;
			case 4:printf("\t 1.Modify With start\n\t 2.Modify With end \n\t Selecat One Optione:");
					scanf("%d",&op);
					if(op==1){
						Modify(Queqs,&start);
					}
					else{
						Modify(Queqs,&end);
					}
					break;
			case 5:printf("\t Program is Exited");
					break;
			default :
				printf("Option is not Valid Please try agien \n ");
				break;
			}
		
     }while(option!=4);
}
void Insarting(int Queqs[],int *start,int *end){
	    int val,option;
	 	if(*end>=4 && *start==0 ){
	 		printf("Queue is Full \n");
		 }
		 else{
		 		printf("Enter your pusing values:");
				scanf("%d",&val);
				if(*start>0){
						printf("1.Add Element in frant.\n 2.Add Element in rear.\n\t Selecat One Optione:");
						scanf("%d",&option);
						if(option==1){
							*start=*start-1;
			 				Queqs[*start]=val;
			 				printf("\n \t Values Insarted \n");
							}
						else{
			 					if(*end>=4){
			 						printf("\t reee is full please select option 1\n");
								 }
								 else{
								 	*end=*end+1;
			 						Queqs[*end]=val;
			 						printf("\n \t Values Insarted \n");
								 }
					}
				}
			else{
		 	if(*start==-1 && *end==-1){
		 		*start=*end=0;
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
	int option;
	if(*start==-1 && *end==-1){
		printf("Queue is Emtye \n");
	}
	else{
			printf("1.Deleting Element in frant.\n 2.Deleting Element in reer.\n");
			scanf("%d",&option);
			if(option==1){
				if(*start==*end){
					printf("%d is Deleting \n",Queqs[*start]);
					printf("\t This is Last Element In Dqueue\n");
					*start=*end=-1;
					
				}
				else{
					printf("%d is Deleting \n",Queqs[*start]);
					*start=*start+1;
					}
			}
			else{
				if(*end==*start){
					printf("%d is Deleting \n",Queqs[*end]);
					*start=*end=-1;
					printf("\t This is Last Element In Dqueue\n");
				}
				else{
					printf("%d is Deleting \n",Queqs[*end]);
					*end=*end-1;
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
		printf("Queue is below:\n");
		printf("Start index is %d and End %d :\n",start, end);
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

