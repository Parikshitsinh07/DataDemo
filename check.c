#include<stdio.h>
void qucikSort(int [],int);
int partition(int [],int,int);
void main(){
	int array[5] = {12,14,50,112,1503};
	 int n = sizeof(array) / sizeof(array[0]);
	qucikSort(array, n);

}
void qucikSort(int array[],int n)
{
	int low,high;
	low = 0;
	high = n;
	partition(array,low,high);
}
int partition(int array[],int low,int high)
{
	
}
