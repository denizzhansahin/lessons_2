#include <stdio.h>
#include <stdlib.h>
//fonksiyon ve dongu ile islemler
struct n{
	int x;
	n *next;
};

typedef n node;

//yazdir
void bastir(node * r){
	//roottan basla ve root olana kadar bastýr,roota esit ise dur
	node *iter = r;
	//ilk elemaný bastir,  el ile
	printf("%d\n",iter->x);
	iter = iter->next;
	while(iter != r){
		printf("%d\n",iter->x);
		iter = iter->next;
	}
}





node  * sil(node *r, int x)
{
	node *temp;
	node *iter = r;
	if(r->x == x)
	{
		while(iter->next!=r){
			iter = iter -> next;
		}
		
		iter -> next = r->next ->next;
		free(r);
		return iter->next;
	}
	
	while(iter->next != r && iter->next->x != x)
	{
		iter = iter -> next;
	}
	
	if(iter->next == r)
	{
		printf("sayi bulunamadi");
		return r;
	}
	
	temp = iter -> next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main(){
	printf("merhaba\n");
	
	node * root; // root yap
	root = (node *)malloc(sizeof(node)); //kutu olustur, bu alaný root gostersin
	root -> next = NULL; //her zaman link list son elemani NULL olmalidir.


	//liste icinde gezecek eleman
	node * iter;
	iter = root;
	int i = 0;
	//eleman ekleme
	for(i=0;i<5;i++){
		
		
		//ekle ve iter'e git, ekle ve iter'e git
		iter->next = (node *)malloc(sizeof(node));
		iter = iter -> next;
		iter->x = i*10;
		iter -> next = NULL;
		
	}
	//ekrana yazdir - void
	bastir(root);
	
	root = sil(root,10);
	bastir(root);
	
}
