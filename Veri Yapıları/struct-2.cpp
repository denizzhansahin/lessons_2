#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char takimAdi[30];
	int kurulus;
}takim;

typedef struct {
	char adSoyad[30];
	int yas;
	// struct icinde struct kullanimi - direct
	takim takim; //ilk takim struct ve ikinci takim degisken
}futbolcu;


int main(){
	
	futbolcu ft;
	strcpy(ft.adSoyad,"Nurullah Aslan");
	ft.yas = 20;
	//struct icindeki struct icine deger gonderme
	strcpy(ft.takim.takimAdi,"Samsunspor");
	ft.takim.kurulus = 1965;
	
	printf("Bilgiler %s %d\n",ft.takim.takimAdi,ft.takim.kurulus);
	
	return 1;
}
