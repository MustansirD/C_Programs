#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	char caStr[]="Hello";
	
	int i = 0;
	while(caStr[i] != '\0')
	{
		printf("[%c]\n",caStr[i]);
		i++;	
	}
	return 0;
}