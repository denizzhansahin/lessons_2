#include <stdio.h>
#include <stdlib.h>

void tasi(int n,char A,char B, char C)
{
	if(n==1) printf("%c --> %c\n",A,B);
	else
	{
		tasi(n-1,A,C,B);
		tasi(1,A,B,C);
		tasi(n-1,C,B,A);
	}
}

int main()
{
	int n;
	printf("n degeri giriniz : ");
	scanf("%d",&n);
	tasi(n,'A','B','C');
	return 0;
}
