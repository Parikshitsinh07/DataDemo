#include<stdio.h>
void main()
{
	int size,i;
	printf("Enter a array of size = ");
	scanf("%d",&size);
	
	int arr[size];
	
	for(i=0;i<size;i++)
	{
		printf("Enter a %d Elements = ",i+1);
		scanf("%d",&arr[i]);	
	}
	
	for(i=0;i<size;i++)
	{
		printf("arr[%d] = %d\n",i+1,arr[i]);
		
	}
	
	
}
