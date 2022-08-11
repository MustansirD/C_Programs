#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	char caStr[]="My name is Mustansir";
	unsigned short usCount = 0;
	char *dpcaStr[10];
	for(int i=0;i<10;i++)
	{
		dpcaStr[i] = NULL;
	}
	
	int j=0,k=0,l=0;
	char *ptr = caStr;
	while(caStr[j]!='\0')
	{
		if(caStr[j] == ' ')
		{	
			dpcaStr[k] = (char *)malloc((usCount+1)*sizeof(char));
			memset(dpcaStr[k],0,usCount+1);
			memcpy(dpcaStr[k],ptr,usCount);
			printf("[%s]\n",dpcaStr[k]);
			ptr = &caStr[j]+1;
			usCount = -1;
			k++;

		}
		usCount++;
		j++;	
	}

	//For last token
	dpcaStr[k] = (char *)malloc((usCount+1)*sizeof(char));
	memset(dpcaStr[k],0,usCount+1);
	memcpy(dpcaStr[k],ptr,usCount);
	printf("[%s]\n",dpcaStr[k]);

	while(k>=0)
	{
		printf("[%s]\n",dpcaStr[k]);
		k--;
	}
	
	return 0;
}