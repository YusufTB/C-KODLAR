#include<stdio.h>

	struct bilgi{
	char name[20];
	int  no;
	struct {
		int gun;
		int ay;
		int yil;
	}dg;
};
typedef struct bilgi bilgi;

int main(){
	
	bilgi a;
	printf("isim giriniz:\n"); scanf("%s",a.name);
	printf("No giriniz:\n");   scanf("%d",&a.no);
	printf("Dogum gununuzu Gun-Ay-Yil biciminde giriniz:\n"); scanf("%d%d%d",&a.dg.gun,&a.dg.ay,&a.dg.yil);
	
	printf("Ýsim: %s\t",a.name);
	printf("No su: %d\t",a.no);
	printf("Dogum tarihi : %d-%d-%d",a.dg.gun,a.dg.ay,a.dg.yil);
	
	return 0;
}
