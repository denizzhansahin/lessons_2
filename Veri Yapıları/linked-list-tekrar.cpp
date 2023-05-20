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
	while(r!=NULL){
		printf("%d\n",r->x);
		r = r->next;
	}
}

//ekleme, her defasinda root'a git 
void ekle(node *r, int x){
	while(r->next!=NULL){
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}
int main(){
	printf("merhaba\n");
	
	node * root; // root yap
	root = (node *)malloc(sizeof(node)); //kutu olustur, bu alaný root gostersin
	root -> next = NULL; //her zaman link list son elemani NULL olmalidir.
	/*
	root -> x = 10; //rootun gosterdigi alana 10 atamasý yap
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 20; //rootun gosterdigi nextin degeri 20, diger kutu
	root -> next -> next -> x = 30;
	root -> next -> next -> next = NULL;
	//liste icinde gezecek eleman
	node * iter;
	iter = root;
	printf("%d\n",iter->x); //10
	iter = iter -> next;
	printf("%d\n",iter->x); //20
	//ekrana yazdir
	int i = 0;
	while (iter->next != NULL){
		i++;
		printf("%d.nci eleman : %d \n",i,iter->x);
		iter = iter ->next;
	}
	*/

	//liste icinde gezecek eleman
	node * iter;
	iter = root;
	int i = 0;
	//eleman ekleme
	for(i=0;i<5;i++){
		ekle(root, i*10);
		/*
		//ekle ve iter'e git, ekle ve iter'e git
		iter->next = (node *)malloc(sizeof(node));
		iter = iter -> next;
		iter->x = i*10;
		iter -> next = NULL;
		*/
	}
	//ekrana yazdir - void
	bastir(root);
}
