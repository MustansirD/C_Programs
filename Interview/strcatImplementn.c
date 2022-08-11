#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *captr1 = "Hello";
	char *captr2 = "World";
	
	char *captr3 = (char *)malloc(strlen(captr1) + strlen(captr2) + 1);//added 1 for NULL
	memset(captr3,0,strlen(captr1) + strlen(captr2) + 1);
	
	unsigned int i = 0;
	while(*captr1!='\0')
	{
		captr3[i] = *captr1;
		i++;
		captr1++;	
	}

	while(*captr2!='\0')
	{
		captr3[i] = *captr2;
		captr2++;
		i++;	
	}

	printf("[%s]\n",captr3);
	
	return 0;
}

char *str 