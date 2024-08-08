#include<stdio.h>
int main()
{
    int i;
    char s[50],ch;
    printf("Enter String : ");
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            s[i]='_';
        }
	}    
    printf("%s",s);
    return 0;
}
