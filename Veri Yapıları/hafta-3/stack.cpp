#include <stdio.h>
#include <stdlib.h>

struct Yigin
{
	int data; //kullanýcýdan alýnan veri
	struct Yigin *next; // sonraki eleman adresi
};
struct Yigin *son=NULL;

void push(int data)
{
	struct Yigin *temp;
	temp = (struct Yigin *)malloc(sizeof(struct Yigin));
	
	if(temp==NULL)
	{
		printf("Yetersiz bellek");
	}
	temp->data=data;
	temp->next=son;
	son=temp;
}

void pop()
{
	if(son==NULL)
	{
		printf("Yigin bos");
		return;
	}
	printf("%d",son->data);
	struct Yigin *ptr;
	ptr=son;
	son=son->next;
	free(ptr);
}

void top()
{
	if(son==NULL)
	{
		printf("Yigin bos");
		return;
	}
	printf("%d",son->data);
}

void size()
{
	int size=0;
	struct Yigin *ptr;
	ptr=son;
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->next;
	}
	printf("Size : %d",size);
}

bool isEmpty()
{
	if(son==NULL)
	{
		return 1;
	}
	return 0;
}

int main()
{
	
	return 0;
}
