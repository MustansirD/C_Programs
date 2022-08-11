#include<stdio.h>

int main(int argc,char **argv)
{
	int sum1=0,sum2=0,arr[10] = {1,2,3,4,5,6,0,8,9,10};
	for(int i=1;i<10;i++)
	{
		sum1 = sum1+arr[i];
		sum2 = sum2+i+1;
	}

	printf("[%d]\n",sum2-sum1);

	return 0;


}