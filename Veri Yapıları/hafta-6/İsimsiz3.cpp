#include <stdio.h>
#include <stdlib.h>

int Pow(int sayi, int kuvvet)
{
	int araSonuc;
	if(kuvvet == 0) return 1;
	if(kuvvet % 2 == 1)
	{
		araSonuc = Pow(sayi,(kuvvet-1)/2);
		return sayi * araSonuc * araSonuc;
	}
	else
	{
		araSonuc = Pow(sayi,kuvvet/2);
		return araSonuc*araSonuc;
	}
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
