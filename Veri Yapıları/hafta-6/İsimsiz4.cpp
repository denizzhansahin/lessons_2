#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main()
{
	int sayi;
	printf("hesaplanacak sayiyi giriniz : ");
	scanf("%d",&sayi);
	printf("%d\n",fibonacci(sayi));
	
	
	int sayi1=0,sayi2=1,sonraki;
	for(int i=1;i<=sayi;i++)
	{
		printf("%d",sayi2);
		sonraki = sayi1 + sayi2;
		sayi1 = sayi2;
		sayi = sonraki;
	}
	return 0;
}

int fibonacci(int x)
{
	if(x==0)
	{
		return 0;
	}
	else if(x==1)
	{
		return 1;
	}
	return fibonacci(x-1)+fibonacci(x-2);
}
