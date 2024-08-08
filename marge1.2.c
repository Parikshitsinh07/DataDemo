/*
Submitted By:-Parikshitsinh vaghela
Entrollment Number:- 212308020
Submitted To:-Meera Kansara
*/

#include<stdio.h>
void mergeSort(int [],int ,int );
void marge(int [],int ,int,int );
void printArry(int[],int);
void main(){
	int len,i;
		printf("Eneter Your Arrya Size:");
		scanf("%d",&len);
	int a[len];
	for(i=0;i<len;i++){
		printf("Eneter Your Element:");
		scanf("%d",&a[i]);
	}
	printf("Before sorting array elements are - \n");
	printArry(a,len);
	mergeSort(a,0,len-1);
	printf("\nAfter sorting array elements are - \n");  
    printArry(a, len); 
}
void merge(int a[],int mid,int left,int end)
{	
	
	int i,j,k, b[end+1];
	i=left; 
	j=mid+1;
	k=left;
	while(i<=mid && j<=end){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=end){
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=left;i<end+1;i++){
		a[i]=b[i];
	}
}
void mergeSort (int a[] ,int left ,int end)
{	

	int mid,count=0;
	
	if(left<end){
		count=count+1;
		printf("%d",count);
		mid=(left+end)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,end);
		merge(a,mid,left,end);
	}
	
}
void printArry(int a[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d\t",a[i]);
	}
}
