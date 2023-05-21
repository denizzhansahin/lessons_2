#include <stdio.h>
#include <stdlib.h>

int Queue[20];
int index = 0;

void enqueue(int data)
{
	if(index == 19)
	{
		printf("Kuyruk dolu\n");
		return;
	}
	Queue[index]=data;
	index++;
}

void dequeue()
{
	if(index==0)
	{
		printf("Kuyruk bos\n");
		return;
	}
	printf("%d",Queue[0]);
	int i = 0;
	for(i;i<index-1;i++)
	{
		Queue[i] = Queue[i+1];
	}
	index--;
}

void front()
{
	if(index==0)
	{
		printf("Kuyruk bos\n");
	}
}

void size()
{
	if(index==0)
	{
		printf("Kuyruk bos\n");
		return;
	}
	printf("Size : %d\n",(index));
}
