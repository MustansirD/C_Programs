#include<stdio.h>
#include<stdlib.h>

struct node
{
	int iData;	
	struct node *psNext;
};

typedef struct node NODE;

NODE *psRoot = NULL;

void append(int iData)
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
		while(psTemp2->psNext != NULL)
		{
			psTemp2 = psTemp2->psNext;
		}

		psTemp2->psNext = psTemp1;
	}
}

unsigned int display(char cFlag)
{
	unsigned uiCount = 0;
	if(psRoot == NULL)
	{
		
	}
	else
	{
		NODE *psTemp1 = psRoot;
		while( psTemp1!=NULL)
		{
			uiCount++;
			if( cFlag == 'Y')
				printf("[%d]\n",psTemp1->iData);
			psTemp1 = psTemp1->psNext;
		}
	}

	return uiCount;
}

void reverse()
{
	if(psRoot == NULL)
	{
		return;
	}
	else
	{
		unsigned int i=0,j=display('n');
		NODE *psTemp1 = psRoot;
		NODE *psTemp2 = psRoot;
		int iTemp = 0;
		
		while(i<j-1)
		{
			unsigned int k=0;
			while(k<j-1)
			{
				psTemp2 = psTemp2->psNext;
				k++;
			}
			iTemp = psTemp2->iData;
			psTemp2->iData = psTemp1->iData;
			psTemp1->iData = iTemp;
			psTemp1 = psTemp1->psNext;
			psTemp2 = psRoot;
			i++;
			j--;
			
		}
	}
}

void delete(unsigned int uiPos)
{
	if( psRoot == NULL || uiPos < 0 || uiPos > display('N'))
	{

	}
	else
	{
		if(uiPos == 1)
		{
			NODE *psTemp1 = psRoot;
			psRoot = psTemp1->psNext;
			psTemp1->psNext = NULL;
			free(psTemp1);
		}
		else
		{
			unsigned int i=1;
			NODE *psTemp1 = psRoot, *psTemp2 = NULL;
			while(i<uiPos-1)
			{
				psTemp1 = psTemp1->psNext;	
			}
			psTemp2 = psTemp1->psNext;
			psTemp1->psNext = psTemp2->psNext;
			psTemp2->psNext = NULL;
			free(psTemp2);
		}

	}
}

int main(int argc,char **argv)
{

	append(10);	
	append(20);
	append(30);
	reverse();
	display('Y');
	printf("After deleting\n");
	delete(2);
	display('Y');
		
	return 0;
	
}