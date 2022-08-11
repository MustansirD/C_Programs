#include<stdio.h>

int main(int argc,char **argv)
{
	typedef struct
	{
		int a;	
		char b;
		float c;
	}S;

	typedef union
	{
		int a;
		char b;
		float c;
	}U;


	S s1;
	s1.a = 10;
	s1.b = 'A';
	s1.c = 19.98;

	U u1;
	u1.a = 10;
	u1.b = 'B';
	u1.c = 9.28;
	

	printf("[%d][%c][%f]\n",s1.a,s1.b,s1.c);
	printf("[][][]\n",u1.a,u1.b,u1.c);

	return 0;

	
}