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
	if(data=='(' || data == '{' || data == '[')
	{
		temp->data=data;
		temp->next=NULL;
		if(son==NULL)
		{
			son=temp;
			return -1;
		}
		temp->next=son;
		son=temp;
	}
	if(data==')')
	{
		if(son==NULL) return 0;
		if(son->data=='(')
		{
			son=son->next;
			return -1;
		}
		else return 0;
	}
	else if(data=='}')
	{
		if(son==NULL) return 0;
		if(son->data=='{')
		{
			son=son->next;
			return -1;
		}
		else return 0;
	}
	else if(data==']')
	{
		if(son==NULL) return 0;
		if(son->data=='{')
		{
			son=son->next;
			return -1;
		}
		else return 0;
	}
	else if(data==']')
	{
		if(son==NULL) return 0;
		if(son->data=='[')
		{
			son=son->next;
			return -1;
		}
		else return 0;
	}
	return -1;
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

void main(int argc, char *argv[])
{
	bool kontrol=true;
	char denklem[20];
	printf("Denklem : ");
	gets(denklem);
	int i=0;
	for(i;i<strlen(denklem);i++)
	{
		kontrol = push(denklem[i]);
		if(!kontrol)
		{
			printf("hatali denklem");
			return 0;
		}
	}
	if(son==NULL)
	{
		printf("Denklem doðru");
	}
	else
	{
		printf("Denklem hatali");
	}
	
	return 0;
}
