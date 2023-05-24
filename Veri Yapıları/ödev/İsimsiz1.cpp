#include <stdio.h>
#include <stdlib.h>

//yapý olustur
struct node{
	int okul_no;
	char isim[50];
	char soyad[50];
	char dersler [][4];
	
	struct node *next;
	struct node *previous;
};
struct node *head=NULL,*tail=NULL;

//sona ekleme
void SonaEkleme()
{
	struct node *tmp, *ptr;
	tmp=(struct node*)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Yetersiz Bellek");
		return;
	}
	printf("Okul no girin : ");
	scanf("%d",&tmp->okul_no);
	
	printf("Isim yaziniz : ");
	scanf("%s",&tmp->isim);
	
	printf("Soyad yaziniz : ");
	scanf("%s",&tmp->soyad);
	
	printf("\n");
	printf("Lütfen dersleri yaziniz, 4 ders girme hakkiniz var.\n");
	printf("Ders 1 : \n");
	scanf("%s",tmp->dersler[0]);
	printf("Ders 2 : \n");
	scanf("%s",tmp->dersler[1]);
	printf("Ders 3 : \n");
	scanf("%s",tmp->dersler[2]);
	printf("Ders 4: \n");
	scanf("%s",tmp->dersler[3]);
	
	tmp->next=NULL;
	tmp->previous=NULL;
	
	if(head==NULL)
	{
		head=tmp;
		tail=tmp;
	}
	else
	{
		tail->next=tmp;
		tmp->previous=tail;
		tail=tmp;
	}
}

//gosterme fonksiyonu
void Goster()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("Liste bos");
		return;
	}
	
	ptr=head;
	while(ptr!=tail)
	{
		printf("Isim : %s \n",ptr->isim);
		printf("Soyad : %s \n",ptr->soyad);
		printf("Okul No : %s \n",ptr->okul_no);
		printf("Ders 1 : %s \n",ptr->dersler[0]);
		printf("Ders 2 : %s \n",ptr->dersler[1]);
		printf("Ders 3 : %s \n",ptr->dersler[2]);
		printf("Ders 4 : %s \n",ptr->dersler[3]);
	}
}

//gosterme fonksiyonu - sadece veri yapilari dersi icin
void Goster()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("Liste bos");
		return;
	}
	
	ptr=head;
	while(ptr!=tail)
	{
		if(ptr->dersler[0]=="VeriYapilari"||ptr->dersler[1]=="VeriYapilari"||ptr->dersler[2]=="VeriYapilari"||ptr->dersler[3]=="VeriYapilari")
		{
			printf("Isim : %s \n",ptr->isim);
			printf("Soyad : %s \n",ptr->soyad);
			printf("Okul No : %s \n",ptr->okul_no);
			printf("Ders 1 : %s \n",ptr->dersler[0]);
			printf("Ders 2 : %s \n",ptr->dersler[1]);
			printf("Ders 3 : %s \n",ptr->dersler[2]);
			printf("Ders 4 : %s \n",ptr->dersler[3]);
		}
		else
		{
			printf("VeriYapilari Dersi alinmamis.");
		}
	}
}

int main()
{
	
	return 0;
}
