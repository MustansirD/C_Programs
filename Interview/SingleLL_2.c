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

	if(psRoot == NULL)
	{
		psRoot = psTemp;
	}
	else
	{
		NODE *psTemp2 = psRoot;
		while(psTemp2->psNext != NULL )
		{
			psTemp2 = psTemp2->psNext;
		}
		psTemp2->psNext = psTemp;
	}
}

int display()
{
	NODE *psTemp = psRoot;
	int iCount = 0;
	if(psTemp == NULL)
	{
		printf("No Nodes present in list to display\n");
		return iCount;
	}
	else
	{
		while(psTemp!=NULL)
		{
			iCount++;
			printf("[%d]\n",psTemp->iData);
			psTemp = psTemp->psNext;
		}
	}
	return iCount;
}

void reverse()
{
	int i=0,iTemp=0;
	int j = display();
	while(i<j-1)
	{
		int k = 0;
		NODE *psTemp = psRoot, *psTemp2 = psRoot;
		while(k<j-1)
		{
			psTemp = psTemp->psNext;
			k++;		
		}
		iTemp = psTemp->iData;
		psTemp->iData = psTemp2->iData;
		psTemp2->iData = iTemp;
		psTemp2 = psTemp2->psNext; 
		i++;
		j--;
	}
}

void delete(unsigned int uiPos)
{
	NODE *psTemp = psRoot;
	if(psTemp == NULL)
	{
		printf("No nodes present in the list\n");
	}
	if(uiPos > display())
	{
		printf("Position to delete the node is out of range\n");
	}
	
	if(uiPos == 1)
	{
		psRoot = psTemp->psNext;
		psTemp->psNext = NULL;
		free(psTemp);
	}
	else
	{	int i = 1;
		while( i < uiPos-1)
		{
			psTemp = psTemp->psNext;	
		}
		NODE *psTemp2 = psTemp->psNext;
		psTemp->psNext = psTemp2->psNext;
		psTemp2->psNext;
		free(psTemp2);
		
	}
}

int main()
{
	append(10);
	append(20);	
	append(30);
	printf("Nodes in the list [%d]\n",display());
	reverse();
	printf("Nodes in the list [%d]\n",display());
	delete(2);
	display();
	printf("FINISHED\n");
	return 0;

}