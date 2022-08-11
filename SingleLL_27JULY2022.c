#include<stdio.h>
#include<stdlib.h>

struct node
{
	int iData;
	struct node *psNext;
};

typedef struct node NODE;

NODE *psRoot = NULL;

void append( int iData)
{

	NODE *psTemp1 = (NODE *)malloc(sizeof(NODE));
	psTemp1->iData = iData;
	psTemp1->psNext = NULL;
	
	if(psRoot == NULL)
	{
		psRoot = psTemp1;
	}
	else
	{
		NODE *psTemp2 = psRoot;
		while( psTemp2->psNext != NULL)
		{
			psTemp2 = psTemp2->psNext;
		}
		
		psTemp2->psNext = psTemp1;
	}
	
}

unsigned int display(char cFlag)
{
	NODE *psTemp1 = psRoot;
	unsigned int uiCount = 0;
	if(psTemp1 == NULL)
	{
		return 0;
	}
	else
	{	
		while(psTemp1 != NULL)
		{
			uiCount++;
			if ( cFlag == 'Y')
			{
				printf("[%d]\n",psTemp1->iData);
			}
			psTemp1 = psTemp1->psNext;
		}
	}

	return uiCount;
}

void reverse()
{
	NODE *psTemp1 = psRoot,*psTemp2 = psRoot;
	unsigned int i=0,j=display('N');
	while(i<j-1)
	{
		unsigned int k=0;
		int iTemp = 0;
		while(k<j-1)
		{
			psTemp1 = psTemp1->psNext;
			k++;
		}
		iTemp = psTemp1->iData;
		psTemp1->iData = psTemp2->iData;
		psTemp2->iData = iTemp;
		psTemp2 = psTemp2->psNext;
		psTemp1 = psRoot;
		i++;
		j--;
		
			
	}
}

void delete(unsigned int uiPos)
{
	NODE *psTemp1 = psRoot;
	if(	psTemp1 == NULL ||
	   	uiPos > display('N') ||
	   	uiPos < 0 )
	{
		printf("Invalid\n");
		return;
	}

	if( uiPos == 1)
	{
		psRoot = psTemp1->psNext;
		psTemp1->psNext = NULL;
		free(psTemp1);	
	}
	else
	{
		unsigned int i=1;
		while(i<uiPos-1)
		{
			psTemp1 = psTemp1->psNext;
			i++;	
		}

		NODE *psTemp2 = psTemp1->psNext;
		psTemp1->psNext = psTemp2->psNext;
		psTemp2->psNext = NULL;
		free(psTemp2);
		
	}
}

int main(int argc,char **argv)
{

	append(10);
	append(20);
	append(30);
	append(40);
	append(50);
	printf("Count=[%d]\n",display('Y'));
	printf("------\n");
	reverse();
	display('Y');
	printf("After deleting\n");
	delete(3);
	display('Y');

	return 0;
	
}