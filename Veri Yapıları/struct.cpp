#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ilk tanimlama yontemi
struct kitap{
	char kitapAdi[30];
	float fiyat;
	int sayfa;
};


//typedef ile tanimlama
/*
typedef struct yazar{//eski yazar
	
}yazar; //yeni yazar
*/

typedef struct {
	char adSoyad[30];
	int yas;
}yazar;
int main(){
	
	//direct
	//dogrudan kullanim, kitap ile kitap1 yapildi
	struct kitap kitap1;
	strcpy(kitap1.kitapAdi, "Turklerin Tarihi");
	kitap1.fiyat = 17.50;
	kitap1.sayfa = 250;
	
	printf("Bilgiler : %s %f %d \n",kitap1.kitapAdi,kitap1.fiyat,kitap1.sayfa);
	
	//undirect
	//pointer ile ulasim,
	//hafizda yer olustur
	//sizeof boyut, malloc alan olusturma
	struct kitap *kitap2 = (struct kitap*)malloc(sizeof(struct kitap));
	strcpy(kitap2->kitapAdi , "Fabrika Ayari ");
	kitap2->fiyat = 16.50;
	kitap2->sayfa = 300;
	
	printf("Bilgiler : %s %f %d\n", kitap2->kitapAdi,kitap2->fiyat,kitap2->sayfa);
	
	
	//typedef ile yapilan - Direct
	yazar yazar1;
	strcpy(yazar1.adSoyad,"Ilber Ortayli");
	yazar1.yas = 74;
	
	printf("Yazar 1 : %s %d\n",yazar1.adSoyad,yazar1.yas);
	
	//typedef - undirect - pointer ile
	yazar *yazar2 = (yazar*)malloc(sizeof(yazar));
	strcpy(yazar2->adSoyad,"Hayati Inanc");
	yazar2->yas = 60;
	
	printf("Yazar 2 : %s %d\n",yazar2->adSoyad,yazar2->yas);
	
	
	return 1;
}
