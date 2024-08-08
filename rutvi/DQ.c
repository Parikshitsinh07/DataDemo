#include(stdio.h)
void insert(int [],int *, int *, int);

void  main()
{
	int opt ,dq[10],r=-1,f=-1;
	int val;
	do
	{
		printf("1.insert in DQ..");
		printf("2.Delete in DQ..");
		printf("3.traves in DQ..");
		printf("select eny option");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Insert your your value:-");
					scanf("%d",val);
					insert(dq,&f,&r,val);
					break;
		}
	}while()
	
}
insert(int dq[],int *f, int *r, int val)
{
	
}
