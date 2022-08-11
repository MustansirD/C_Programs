#include<stdio.h>

int main()
{
	int l=0,b=0,area=0,numOfSq=0,a=0;
	
	printf("Enter len and breadth for rectangle:");
	scanf("%d %d",&l,&b);
	printf("l=%d and b=%d\n",l,b);
	a = l*b;
	
	if ( l < b )
		b = l;
	
	while(1)
	{
		numOfSq = numOfSq + a/(b*b);
		a = a%(b*b);
		if ( a == 0)
			break;
		while(1)
		{
			if ((b*b) < a)
			{
				break;
			}
			else
				b = b-1;
		}
	}
	
	printf("Num of squares:[%d]\n",numOfSq);
}