#include<stdio.h>
#include<stdlib.h>

struct node
{
	int iData;
	struct node* psNext;
};

typedef struct node NODE;

NODE *psRoot = NULL;

void append(int data)
{
	NODE *psTemp,*psPtr = NULL;
	psTemp = (NODE *)malloc(sizeof(NODE));
	psTemp->iData = data;
	psTemp->psNext = NULL;

	if( psRoot == NULL )
	{
		psRoot = psTemp;
	}
	else
	{
		psPtr = psRoot;		
		while( psPtr->psNext != NULL )
    		{
      			psPtr = psPtr->psNext;
    		}
    		psPtr->psNext = psTemp;
			
	}
}

void display()
{
	NODE *psTemp = psRoot;
	
	if(psTemp == NULL)
	{
		printf("No nodes present in list\n");
		return;
	}
	else
	{	
		while(psTemp != NULL )
		{
			printf("Data [%d]\n",psTemp->iData);
			psTemp = psTemp->psNext;
		}
	}
	
}

unsigned int lenOfList()
{
	NODE *psTemp = psRoot;
	unsigned int uiCount = 0;
	
	if ( psTemp == NULL )
	{
		return 0;
	}	
	else
	{
		while(psTemp != NULL)
 		{
			uiCount++;
			psTemp = psTemp->psNext;
		}
	}
	return uiCount;
}

void reverse2()
{
	int i=1,j=lenOfList(),k=0,iTemp=0;
	NODE *p = psRoot,*q = psRoot;
	while(i<j)
	{
		k=1;
		while(k<j)
		{
			q = q->psNext;
			k++;
		}	
		iTemp = p->iData;
		p->iData = q->iData;
		q->iData = iTemp;
		p = p->psNext;
		q = psRoot;		
		i++;		
		j--;
	}
	
	
}

void reverse()
{
	int iLen = 0,k=0;
	iLen = lenOfList();
	int *iaArr = NULL;
	iaArr = (int *)malloc(iLen*sizeof(int));
	NODE *psPtr = NULL;

	if ( iLen == 0 )
	{
		return;
	}
	else
	{
		psPtr = psRoot;
		while( psPtr != NULL)
		{
			//printf("[%p]\n",(void*)iaArr);
			*iaArr = psPtr->iData;
			iaArr++;
			psPtr = psPtr->psNext;
		}
	}

	printf("[%p]\n",(void *)iaArr);
	iaArr = iaArr - iLen;
	printf("[%p]\n",(void *)iaArr);

	int i=0,j=iLen-1,iTemp=0;
	while(i<j)
	{	
		iTemp = iaArr[i];
		iaArr[i] = iaArr[j];
		iaArr[j] = iTemp;
		i++;
		j--;
	}

	psPtr = psRoot;
	while(psPtr!=NULL)
	{
		psPtr->iData = *iaArr;
		iaArr++;
		psPtr = psPtr->psNext;
	}

}

void delete(unsigned int uiPos)
{
	NODE *psTemp = psRoot;
	unsigned int uiCount = 0;
	
	
	if ( uiPos > lenOfList() )
	{
		printf("Error\n");
		return;
	}
	else if ( uiPos == 1 )
	{
		psTemp = psRoot;
		psRoot = psTemp->psNext;
		psTemp->psNext = NULL;
		free(psTemp);
	}
	else
	{
		int i = 1;
		NODE *p = psRoot,*q = NULL;

		while( i < uiPos-1 )
		{
			p = p->psNext;	
			i++;
		}
		
		q = p->psNext;
		p->psNext = q->psNext;
		q->psNext = NULL;
		free(q);
						
		
		/*
		root-1000 1000[1][2000]->[3000] 2000[2][3000]->NULL 3000[3][4000] 4000[4][NULL]
		p-1000
		q-2000
		*/
		
				
	}
		
}

int main(int argc, char **argv)
{
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	display();
	printf("len of list [%d]\n",lenOfList());
	reverse2();
	display();
	reverse2();
	display();
	delete(2);
	display();
	delete(1);
	display();
	//delete();
	return 0;
}




