#include<stdio.h>
void countsort(int[],int n,int pos);
void radixsort(int[],int n);
int getmax(int[],int);
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
       radixsort(a,n);
       printf("\nafter sort element of an array ");
       for(i=0;i<n;i++)
       {
         printf("%d ",a[i]);
         
       }
       return 0;
}
int getmax(int a[],int n)
{
	int max=a[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		  max=a[i];
		  
	}
	return max;
}
void countsort(int arr[], int n, int pos) 
{  
  int result[n + 1];  
  int count[10] = {0};
  int i;    
  
    for (i = 0; i < n; i++)  
    count[(arr[i] / pos) % 10]++;  
      
    for (i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  
   
  for ( i = n - 1; i >= 0; i--) {  
    result[count[(arr[i] / pos) % 10] - 1] = arr[i];  
    count[(arr[i] / pos) % 10]--;  
  }  
  
  for (i = 0; i < n; i++)  
    arr[i] = result[i];  
}  

void radixsort(int arr[], int n) {  
  
  int max_element = getmax(arr, n);  
  int pos;  
  for ( pos = 1; max_element / pos > 0; pos *= 10)  
    countsort(arr, n, pos);  
}  
