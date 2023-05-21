#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int data;
	struct Queue *nextNode;
};
struct Queue *headNode=NULL;
struct Queue *rearNode=NULL;

void enqueue(int data)
{
	struct Queue *tmp;
	tmp(struct Queue *)malloc(sizeof(struct Queue));
	if(tmp==NULL)
	{
		printf("Yetersiz bellek\n");
		return;
	}
	tmp->data=data;
	if(headNode==NULL)
	{
		headNode = tmp;
		rearNode = tmp;
		rearNode -> nextNode = NULL;
		return;
	}
	rearNode ->nextNode=tmp;
	rearNode=tmp;
	rearNode->nextNode=NULL;
}

void dequeue()
{
	struct Queue *ptr;
	if(headNode == NULL)
	{
		printf("Kuyruk bos\n");
		return;
	}
	printf("%d\n",headNode->data);
	if(headNode->nextNode==rearNode)
	{
		rearNode = NULL;
	}
	ptr = headNode;
	headNode=headNode->nextNode;
	free(ptr);
}

void front()
{
	if(headNode == NULL)
	{
		printf("Kuyruk bos\n");
		return;
	}
	printf("%d\n",headNode->data);
}

void size()
{
	int size = 0;
	struct Queue *ptr;
	ptr = headNode;
	if(headNode==NULL)
	{
		printf("Kuyruk bos\n");
		return;
	}
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->nextNode;
	}
	printf("Size : %d\n",size);
}
