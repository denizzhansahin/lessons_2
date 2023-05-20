#include <stdio.h>
#include <stdlib.h>


//Linkedi List
struct node {
	int data;
	struct node *next; //kendisinden sonrakini isaret etti
};

//Head ve Tail - liste basi ve sonu
struct node *head = NULL;
struct node *tail = NULL;

//Add Node - listenin sonuna ekleme
int addNode(int data){
	
	//Lik-nked list boslugu kontrol et, ilk elemana bak
	if(head==NULL){
		
		struct node *newNode = (struct node *)malloc(sizeof(struct node)); //alan olustur
		newNode->data = data; //eleman ekle
		newNode->next = NULL; //sonrakini goster
		
		head = tail = newNode; //ilk elemana esitle
	}
	 //Listede eleman var ise uc adimda islem yap
	else{
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		//yeni elemani ekle ve sonu NULL gostersin
		newNode->data = data;
		newNode->next = NULL;
		//sondaki eleman ise yeni eleman olsun
		tail->next = newNode;
		tail= newNode; //listenin sonu guncellensin
	}
	
	return 1;
}

// Add Node to Head
int addNodeHead(int data){
	//liste bosluk durumu,liste basina bak
	if(head==NULL){
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		
		head = tail = newNode;
	}
	else{
		//eger liste dolu ise
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = head;
		
		head = newNode;
	}
}


//Print
int print(){
	printf("Liste :");
	//listenin basini goster
	struct node *index = head;
	//NULL gelene kadar yazdir
	while(index!=NULL)
	{
		printf("%d - ",index->data);
		index = index->next;
	}
	printf("\n");
	
	return 1;
}


//Delete Node
int delete1(int data){
	
	struct node *prev = NULL; //silinenecek elemandan onceki eleman isaretcisi olacak
	struct node *index = head; //ilk elemani ekle
	
	//liste bos ise
	if(head==NULL){
		printf("Liste bos!");
		return 1;
	}
	
	if(head->data==data){ // listenin basindaki eleman mi? aranan eleman ise
		
		struct node *t = head;
		 //listenin basini silmek icin, hafizada durmammasi icin
		head = head->next;
		free(t);
		return 1;
	}
	
	//liste bos degilse sirasi ile eleman gez
	//listede var mi yoksa listede yok mu
	while(index!=NULL && index->data!=data){
		//listenin sonuna kadar NULL gelene kadar git ve aranan eleman degilse
		prev = index; //listede yok ise onceki elemani tut
		index = index->next; // diger elemana gec
	}
	
	if(index==NULL){
		printf("listede istenen deger bulunamadi");
		return 1;
	}
	
	prev->next = index->next; //silinenecek elemandan onceki elemanin isaretcisine silinenecek elemandan sonraki elemanin degerini isaret ettir.
	
	//eger son eleman ise silinecek eleman, tailden onceki elemani  al
	if(tail->data==data){
		tail = prev;
	}
	
	free(index);
	
	return 1;
}

int main(){
	
	//eleman ekleyecek fonksiyon
	
	addNode(10);
	addNode(14);
	addNode(16);
	addNode(19);
	addNode(10);
	addNode(12);
	addNode(14);
	addNode(16);
	addNode(19);
	addNodeHead(15);
	
	print();

	addNodeHead(848);

	print();

	addNode(213);

	print();
	
	delete1(848);
	print();

	delete1(489798);
	print();
	
	delete1(848);
	print();
	
	delete1(12);
	print();

	
	
	return 1;
}
