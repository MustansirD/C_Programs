#include<stdio.h>
#include<string.h>

char * mystrstr(char *p1, char *p2)
{
	char *pRet = NULL;
	for(int i=0;i<strlen(p1);i++)
	{
		if( memcmp(p1+i,p2,strlen())==0)	
		
	}
}

int main(int argc, char **argv)
{
	char str1[] = "Mustansir";
	char str2[] = "tan";

	for(int i = 0;i < strlen(str1);i++)
	{
		if ( memcmp(str1+i,str2,strlen(str2)) == 0 )
		{
			printf("[%s]\n",str1+i);
			break;
		}
	}

	return 0;
}