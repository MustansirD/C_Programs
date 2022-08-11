#include<stdio.h>
#include<string.h>

int main()
{
    char caMMM[3+1];
	unsigned int uiDay=0,uiYear=0,uiHour=0,uiMin=0,uiSec=0;

	memset(caMMM,0,sizeof(caMMM));
	
	
	//char *caStr="Current local time and date: Wed Jul 13 15:53:52 2022";
	char *caStr="Current local time and date: Wed Jul 13 15:53:52 2022";
	sscanf(caStr,"%*s %*s %*s %*s %*s %*s %s %d %d%*c%d%*c%d %d",caMMM,&uiDay,&uiHour,&uiMin,&uiSec,&uiYear);
	
	printf("[%s][%d][%d][%d][%d][%d]\n",caMMM,uiDay,uiHour,uiMin,uiSec,uiYear);
	
	return 0;
}