#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char isim[20];
	struct Node *nextNode;
};

struct Node *havaleHeadNode=NULL,*havaleRearNode=NULL;
struct Node *paraYatirmaHeadNode=NULL,*paraYatirmaRearNode=NULL;
struct Node *paraCekmeNode=NULL,*paraCekmeRearNode=NULL;

void enqueue()
{
	struct Node *tmp;
	int secim;
	tmp = (struct Node*)malloc(sizeof(struct Noded));
	if(tmp==NULL)
	{
		printf("Yeterli alan yok\n"),
		return;
	}
	printf("Isminiz : ");
	scanf("%s",&tmp->isim);
	tmp->nextNode=NULL;
	printf("\n1-Havale\n2-Para Yatirma\n3-Para Cekme\nsecim yapiniz : ");
	scanf("%d",&secim);
	if(secim!=1&&secim!=2&&secim != 3)
	{
		printf("Hatali secim\n");
		free(tmp);
		return;
	}
	
	if(secim==1)
	{
		if(havaleHeadNode==NULL)
		{
			havaleHeadNode=tmp;
			havaleNode->nextNode=NULL;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
		else
		{
			havaleRearNode->nextNode=tmp;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
	}
	if(secim==2)
	{
		if(havaleHeadNode==NULL)
		{
			havaleHeadNode=tmp;
			havaleNode->nextNode=NULL;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
		else
		{
			havaleRearNode->nextNode=tmp;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
	}
	if(secim==2)
	{
		if(havaleHeadNode==NULL)
		{
			havaleHeadNode=tmp;
			havaleNode->nextNode=NULL;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
		else
		{
			havaleRearNode->nextNode=tmp;
			havaleRearNode=tmp;
			havaleRearNode->nextNode=NULL;
		}
	}
}
