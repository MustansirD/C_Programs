#include<stdio.h>
#include<stdlib.h>

struct node
{
	int iData;
	struct node *psNext;
};

typedef struct node NODE;

NODE *psRoot = NULL;

void append(int data)
{
	NODE *psTemp = (NODE *)malloc(sizeof(NODE));
	psTemp->iData = data;
	psTemp->psNext = NULL;

	if( psRoot == NULL )
	{
		psRoot = psTemp;
	}
	else
	{
		NODE *psTemp2 = psRoot;
		while(psTemp2->psNext != NULL)
		{
			psTemp2 = psTemp2->psNext;
		}
		psTemp2->psNext = psTemp;
	}
}

unsigned int display(char cFlag)
{
	unsigned int uiCount = 0;
	NODE *psTemp = psRoot;
	
	if(psTemp == NULL)
	{
		return 0;
	}	
	else
	{
		while( psTemp != NULL)
		{
			uiCount++;
			if(cFlag == 'Y')
				printf("[%d]\n",psTemp->iData);
			psTemp = psTemp->psNext;
		}
		
	}
	return uiCount;
}

void reverse()
{
	unsigned int i=0,j=display('N');
	int iTemp=0;
	NODE *psTemp1 = psRoot, *psTemp2 = psRoot;
	while(i<j-1)
	{
		int k=0;
		while(k<j-1)
		{	
			psTemp1 = psTemp1->psNext;
			k++;
		} 
		iTemp = psTemp1->iData;
		psTemp1->iData = psTemp2->iData;
		psTemp2->iData = iTemp;

		psTemp1 = psRoot;
		psTemp2 = psTemp2->psNext;	
		i++;
		j--;
	}
}

void delete(unsigned int uiPos)
{
	if(uiPos > display('N') || uiPos < 1)
	{
		printf("Invalid\n");
		return;
	}

	if( uiPos == 1)
	{
		NODE *psTemp = psRoot;
		psRoot = psTemp->psNext;
		psTemp->psNext = NULL;
		free(psTemp);
	}
	else
	{	unsigned int i = 1;
		NODE *psTemp1 = psRoot, *psTemp2 = NULL;
		while( i < uiPos-1 )
		{
			i++;
			psTemp1 = psTemp1->psNext;
				
		}
		
		psTemp2 = psTemp1->psNext;
		psTemp1->psNext = psTemp2->psNext;
		psTemp2->psNext = NULL;
		free(psTemp2);
		
	}
}

int main(int argc,char **agrv)
{

	append(10);
	append(20);
	printf("Node present in the list [%d]\n",display('N'));
	append(30);
	append(40);
	append(50);
	printf("Node present in the list [%d]\n",display('N'));
	display('Y');
	reverse();
	display('Y');
	printf("After deleting\n");
	delete(3);
	display('Y');

	return 0;
	
}