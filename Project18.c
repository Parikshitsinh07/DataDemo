#include<stdio.h>
void quicksort(int[],int, int);
int main()
{
	   int i,n,a[30];
	   printf("\nenter size of an array ");
       scanf("%d",&n);
       printf("\nenter element of an array\n");
       for(i=0;i<n;i++)
       {
         scanf("%d",&a[i]);
         
       }
	   printf("\nbefore sort element of an array ");
       for(i=0;i<n;i++)
       {
         printf("%d ",a[i]);
         
       }
       quicksort(a,0,n-1);
       printf("\nafter sort element of an array ");
       for(i=0;i<n;i++)
       {
         printf("%d ",a[i]);
         
       }
      
	return 0;
}
void quicksort(int a[],int first,int last)
{
	int i,j,pivot,temp;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot] && i< last)
			{
				i++;
			}
			while(a[i]>a[pivot])
			{
				i++;
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
			
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
}
