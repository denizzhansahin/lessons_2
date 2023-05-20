#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char takimAdi[30];
	int kurulus;
}takim;

typedef struct {
	char adSoyad[30];
	int yas;
	//struct icinde strucr kullanimi - pointer ile undirect
	takim *takim;
}futbolcu;

int main(){
	
	//pointer ile
	takim *tk = (takim*)malloc(sizeof(takim));
	strcpy(tk->takimAdi, "Samsunspor");
	tk->kurulus = 1965;
	
	futbolcu ft;
	strcpy(ft.adSoyad,"Ilyas Kubilay Yavuz");
	ft.yas = 26;
	ft.takim = tk;
	
	printf("Oyuncu Bilgiler : %s %d\n",ft.adSoyad,ft.yas);
	printf("Oyuncu Takim    : %s %d\n",ft.takim->takimAdi,ft.takim->kurulus);
	
	return 1;
}
