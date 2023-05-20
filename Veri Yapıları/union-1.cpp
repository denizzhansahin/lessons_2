#include <stdio.h>
#include <string.h>
#include <stdlib.h>


union ogrenci{
	char isim[20];
	int no;
	float ort;
};


typedef union{
	char isim[20];
	int yas;
}ogretmen;


int main(){
	
	//union boyut ogrenme
	printf("Boyut- byte %ld Byte \n",sizeof(union ogrenci));
	
	union ogrenci o;
	strcpy(o.isim,"Denizhan");
	printf("%s\n",o.isim);
	o.no = 20;
	printf("%d\n",o.no);
	printf("%s\n",o.isim);
	o.ort = 2.00;
	printf("%.1f\n",o.ort);
	printf("%d\n",o.no);
	printf("%s\n",o.isim);
	//her her deger atamasi sonucu ile onceki veriler uzerine yazma olur - override - ortak hafiza nedeni icin
	
	printf("Bilgiler : %s \t %d \t %.2f\n\n",o.isim,o.no,o.ort);
	
	//typedef ile kullanim
	ogretmen ogrt;
	strcpy(ogrt.isim,"Ismail");
	printf("%s\n",ogrt.isim);
	ogrt.yas = 35;
	printf("%d\n",ogrt.yas);
	printf("%s\n",ogrt.isim);
	
	printf("Bilgiler : %s \t %d \n",ogrt.isim,ogrt.yas);
	
	return 1;
}
