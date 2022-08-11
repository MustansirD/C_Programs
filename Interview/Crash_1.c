#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *ptr = NULL;
	ptr = (char *)malloc(10);
	strcpy(ptr,"hello");
	free(ptr);

	printf("bye");
	
	return 0;
}