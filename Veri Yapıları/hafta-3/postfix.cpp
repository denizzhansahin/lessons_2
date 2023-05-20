#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	struct Stack *previous;
};
struct Stack *son=NULL;

void Hesaplama()
{
	char islem[20];
	char karakter[2];
	printf("islemi giriniz");
	gets(islem);
	int i = 0;
	int uzunluk=strlen(islem);
	for(i;i<uzunluk;i++)
	{
		strncpy(karakter,islem,1)
		if(isDigit(karakter[0]))
		{
			temp = (struct Stack*)malloc(sizeod(struct Stack));
			temp->data = atoi(karakter);
			temp-xprevious=NULL;
			if(son==NULL)
			{
				son = temp;
			}
			else
			{
				temp->previous = son;
				son = temp;
			}
			
		}
		else
		{
			if(karakter[0]=='-')
			{
				son->data=(son->previous->data) - (son->data)
				son->previous = son->previous->previous;
			}
			
			if(karakter[0]=='+')
			{
				son->data=(son->previous->data) - (son->data)
				son->previous = son->previous->previous;
			}
			
			if(karakter[0]=='*')
			{
				son->data=(son->previous->data) - (son->data)
				son->previous = son->previous->previous;
			}
			
			if(karakter[0]=='/')
			{
				son->data=(son->previous->data) - (son->data)
				son->previous = son->previous->previous;
			}
		}
		int j;
		for(j=1;j<strlen(islem);j++)
		{
			islem[j-1]=islem[j];
		}
		islem[strlen(islem)-1] = NULL;

	}
	printf("sonuc : %d",son->data);
}
