#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct INVENTORY
{
	char caItem[100];
	unsigned int uiQuantity;
	char caUnit[10];
	float fPricePerUnit;
};
typedef struct INVENTORY INVENTORY;

int main()
{
	FILE *pFile1 = NULL;
	int iRetFromScanf = 0;
	INVENTORY s1;
	
	memset(&s1,0,sizeof(s1));
	pFile1 = fopen("sample.txt","r");
	if (pFile1 == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	
	rewind(pFile1);
	
	printf("Please find the orders details below\n");
	printf("Item\tQuantity\tTotalPrice\n");
	
	while(1)
	{
		iRetFromScanf = fscanf(pFile1,"%s %d %f\n",s1.caItem,&s1.uiQuantity,&s1.fPricePerUnit);
		//Note - element fPricePerUnit will be used for total price
	
		if (iRetFromScanf == 3 )
			printf("%s\t%d\t\t%f\n",s1.caItem,s1.uiQuantity,s1.fPricePerUnit);
		if ( iRetFromScanf == EOF )
		{
			printf("\n");
			break;
		}
	}

	fclose(pFile1);	
	
	return 0;
}