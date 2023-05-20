#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct liste{
 int deger;
 struct liste *onceki,*sonraki;
}denizhan;
int main()
{
 denizhan *p,*q;
 p=q=new denizhan;

 q->deger = 0;
 q->onceki=NULL;
 for(int i=1;i<10;i++)
 {
  p->sonraki=new denizhan;
 
 p->sonraki->onceki=p;
  p=p->sonraki;
  p->deger = i*10;
 }
 p->sonraki=NULL;
 for(p=q;p->sonraki!=NULL;p=p->sonraki)
 {
  printf(" denizhan cift yonlu liste degerleri :  %d\n",p->deger);
 }

 return 0;
}
 
