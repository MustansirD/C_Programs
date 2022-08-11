#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
	int iaNum[9] = {1,2,3,4,5,6,7,8,9};
	char caStr[] = "CISCO";
	
	int i=0,j=sizeof(iaNum)/sizeof(iaNum[0])-1,temp=0;

	while(i<j)
	{
		temp = iaNum[i];
		iaNum[i] = iaNum[j];
		iaNum[j] = temp;
		i++;
		j--;
	}

	for(int k=0;k<(sizeof(iaNum)/sizeof(iaNum[0]));k++)
	{
		printf("[%d]",iaNum[k]);
	}
	printf("\n");

	i=0;
	j=strlen(caStr)-1;
	char ch=0;

	while(i<j)
	{
		ch = caStr[i];
		caStr[i] = caStr[j];
		caStr[j] = ch;
		i++;
		j--;
	}

	printf("[%s]",caStr);
	printf("\n");
	
	return 0;

}