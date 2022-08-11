#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dirent.h>

static void DisplayInventory(void);
static void PlaceOrder(char *caOrderFile);
static int IsItemValid(char *caItem,unsigned int uiQuantity,FILE *pFile1,float *pfPricePerUnit) ;
static void CreateTimeStamp(char *caTimeStamp);
static void CheckOut(char *caOrderFile);
static void DisplayTxn();

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
  char ch;
  char caOrderFile[100];
  
  DisplayInventory();
  do
  {
	  printf("Enter choice\n");
	  printf("1. Place order\n");
	  printf("2. Checkout\n");
	  printf("3. Display Inventory\n");
	  printf("4. Display the txn for a user\n");
	  printf("*. Exit\n");
	  scanf(" %c",&ch);
	  switch(ch)
	  {
		  case '1': PlaceOrder(caOrderFile);
					printf("\nYour txn id for shopping is [%s]\n",caOrderFile);	
					printf("Note: Please checkout to complete order else start with new txn id for placing order again!!!\n\n");
					break;
		  case '2': CheckOut(caOrderFile);
					break;
		  case '3': DisplayInventory();
					break;
		  case '4': DisplayTxn();
		  case '*': break;
		  default : printf("Incorrect choice entered, pls try again\n");
					break;
		  
	  }
	  
  }while(ch != '*');  
  
  return 0;
}

static void DisplayInventory()
{
	
  FILE *pFile1 = NULL;
  int iRetFromScanf=0;
  INVENTORY s1;
 
  memset(&s1,0,sizeof(INVENTORY));
  pFile1 = fopen("Inventory.txt","r");
  if (	pFile1 == NULL )
  {
	printf("Inventory.txt file cannot be opened\n");
	exit(1);
  }
  fscanf(pFile1,"%*[^\n]\n");//skips the first line
  printf("\t\tMENU\t\n");
  printf("--------------------------------------------------------------\n");
  printf("Item\tQuantity Available\tUnit\tPricePerUnit\n");
  while(1)
  {
	iRetFromScanf = fscanf(pFile1,"%[^,],%d,%[^,],%f\n",s1.caItem,&s1.uiQuantity,s1.caUnit,&s1.fPricePerUnit);
	//printf("[%d]",iRetFromScanf);
	if (iRetFromScanf == 4 )
		printf("%s\t%d\t\t\t%s\t%f\n",s1.caItem,s1.uiQuantity,s1.caUnit,s1.fPricePerUnit);
	if ( iRetFromScanf == EOF )
	{
		printf("\n");
		break;
	}
  }

  fclose(pFile1);
	
}

static void PlaceOrder(char *caOrderFile)
{
	FILE *pFile1 = NULL,*pFile2 = NULL;
	char caItem[100],caUserName[100];
	unsigned int uiQuantity = 0;
	float fPricePerUnit;
	char ch = 0;
	char caTimeStamp[15 + 1];//DDMMMYYYYHHMMSS
	
	
	memset(caItem,0,sizeof(caItem));
	memset(caUserName,0,sizeof(caUserName));
	memset(caTimeStamp,0,sizeof(caTimeStamp));
	memset(caOrderFile,0,sizeof(caOrderFile));
	
	printf("Enter your username:");
	scanf(" %s",caUserName);
	
	pFile1 = fopen("Inventory.txt","r");
	
	CreateTimeStamp(caTimeStamp);
	
	sprintf(caOrderFile,"%s_%s.txt",caUserName,caTimeStamp);
	
	pFile2 = fopen(caOrderFile,"w");
	
	while(1)
	{
		memset(caItem,0,sizeof(caItem));
		uiQuantity = 0;
		
		
		printf("Enter item:");
		while((getchar())!='\n');
		scanf(" %s",caItem);
		strlwr (caItem);
		printf("Enter Quantity:");
		scanf(" %d",&uiQuantity);
		if ( IsItemValid(caItem,uiQuantity,pFile1,&fPricePerUnit) != 0 )
		{
			printf("Item is not present in inventory or quantity is invalid(below)\n");
			printf("Item and quantity [%s][%d]\n",caItem,uiQuantity);
			
			printf("Type N/n to stop shpping else type any char to continue:");
		    scanf(" %c",&ch);
		    if ( ch == 'N' || ch == 'n')
			  break;
			continue;
		}
		
		printf("Item and quantity [%s][%d]\n",caItem,uiQuantity);
		
		fprintf(pFile2,"%s %d %lf\n",caItem,uiQuantity,fPricePerUnit*((float)uiQuantity));
		
		printf("Type N/n to stop shpping else type any char to continue:");
		scanf(" %c",&ch);
		if ( ch == 'N' || ch == 'n')
			break;
	}
	
	fclose(pFile1);
	fclose(pFile2);

}

static int IsItemValid(char *caItem,unsigned int uiQuantity,FILE *pFile1,float *pfPricePerUnit)
{
	INVENTORY s1;
	char cItemVerified = 0;
	int iRetFromScanf = 0;
	
	memset(&s1,0,sizeof(s1));
	
	//fseek(pFile1,0,1);
	rewind(pFile1);
	
	fscanf(pFile1,"%*[^\n]\n");//skips the first line
		
	while(1)
	{
		iRetFromScanf = fscanf(pFile1,"%[^,],%d,%[^,],%f\n",s1.caItem,&s1.uiQuantity,s1.caUnit,&s1.fPricePerUnit);
		if ( iRetFromScanf == 4 )
		{
			strlwr(s1.caItem);
			if ( strcmp(s1.caItem,caItem) == 0 )
			{
				if ( uiQuantity > 0 && uiQuantity <= s1.uiQuantity )
				{
					cItemVerified = 1;
					*pfPricePerUnit = s1.fPricePerUnit;
					break;
				}
			}
		}
		if ( iRetFromScanf == EOF )
			break;
	}
	
	if ( cItemVerified == 1 )
		return 0;
	else
		return 1;

}

static void CreateTimeStamp(char *caTimeStamp)
{
	time_t rawtime;
	struct tm * timeinfo;
	char caMMM[3+1];
	unsigned int uiDay=0,uiYear=0,uiHour=0,uiMin=0,uiSec=0;
	
	memset(caMMM,0,sizeof(caMMM));

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "%s", asctime (timeinfo) );
	sscanf(asctime(timeinfo),"%*s %s %d %d%*c%d%*c%d %d",caMMM,&uiDay,&uiHour,&uiMin,&uiSec,&uiYear);
	sprintf(caTimeStamp,"%02d%s%04d%02d%02d%02d",uiDay,caMMM,uiYear,uiHour,uiMin,uiSec);
	
}

static void CheckOut(char *caOrderFile)
{
	FILE *pFile1 = NULL;
	INVENTORY s1;
	int iRetFromScanf = 0;
	
	memset(&s1,0,sizeof(s1));
	pFile1 = fopen(caOrderFile,"r");
	if (pFile1 == NULL)
	{
		printf("Error opening file [%s]\n",caOrderFile);
		exit(1);
	}
	
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
	
}

static void DisplayTxn()
{
	char caUserName[100];
	DIR *d = NULL;
    struct dirent *dir = NULL;
	unsigned short usLen = 0;
	char ch = 0;
	
	
	memset(caUserName,0,sizeof(caUserName));
	
	printf("Enter your username:");
	scanf(" %s",caUserName);
	
	usLen = strlen(caUserName);
	
	
	if ( usLen <= 0)
	{
		printf("Username not valid\n");
		return;
	}

    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
			if ( memcmp(caUserName,dir->d_name,usLen) == 0 )
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
	
	printf("Enter the txn id to display the order details else enter * to return from menu\n");
	
	
	
}



