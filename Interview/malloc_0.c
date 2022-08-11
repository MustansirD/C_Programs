#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	char *ptr = (char *)malloc(0);
	*ptr = 'A';

	if ( ptr == NULL)
	{
		printf("notok");
	}
	else
	{
		printf("[%p][%c]\n",(void *)ptr,*ptr);
		printf("ok");
	}

	return 0;
}