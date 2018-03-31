#include<stdio.h>
#include<string.h>
void liste(struct ogrenci);
struct ogrenci{
	char ad[50];
	char bolum[50];
	int  sinif;
	float ort;
}ogr1={"Yusuf","Bilgisayar Muhendisligi",1,3.37};
void liste(struct ogrenci ogr){
	printf("%s\n",ogr.ad);
	printf("%s\n",ogr.bolum);
	printf("%d\n",ogr.sinif);
	printf("%.2f",ogr.ort);
}
int main(){
	
	liste(ogr1);
	
	return 0;
}

