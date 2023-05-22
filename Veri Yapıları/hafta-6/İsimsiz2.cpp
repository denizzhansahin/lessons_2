#include <stdio.h>
#include <stdlib.h>

int Pow(int alt, int ust)
{
	if(ust==0) return 1;
	else if(ust==1) return alt;
	int araSonuc;
	araSonuc=Pow(alt,ust-1);
	return araSonuc*alt;
}

int main()
{
	int sayi1,sayi2;
	printf("Ust hesaplanacak sayiyi giriniz : ");
	scanf("%d",&sayi1);
	printf("Ust sayisini giriniz : ");
	scanf("%d",&sayi2);
	printf("%d\n",Pow(sayi1,sayi2));
	return 0;
}
