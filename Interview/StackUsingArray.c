#include<stdio.h>

#define MAX_SIZE 10

struct stack
{
	int data[MAX_SIZE];
	int top;
};

typedef struct stack STACK;

STACK s1;

void push(int data)
{
	if(s1.top == MAX_SIZE-1)
	{
		printf("Stack overflow");
		return ;
	}

	s1.top++;
	s1.data[s1.top] = data;
	
}

void pop()
{
	if(s1.top == -1)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("pop element is [%d]\n",s1.data[s1.top]);
	s1.top = s1.top - 1; 
		
}

int main(int argc,char **argv)
{
	s1.top = -1;
	push(10);
	push(20);
	pop();
	pop();
	pop();
	pop();

	return 0;	
}

