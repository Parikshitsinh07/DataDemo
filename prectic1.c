#include<stdio.h>
int main(){
		int num;
		if(scanf("%d",&num)==1){
				if(num > 1 || num <100 ){
					printf("%d",num);	
				}	
				else{
					printf("invalid");
				}
		}else{
			printf("NOO");
		}
		printf("%d   %c", scanf("%d",&num));
		return 0;	
}
