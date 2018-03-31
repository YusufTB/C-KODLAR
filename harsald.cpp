#include<stdio.h>
int main(){
	int i,sayi,toplam=0,harsald;
	printf("lutfen sayiyi giriniz");
	scanf("%d",&sayi);
	harsald=sayi;
	while(sayi>=10){
		i=sayi%10;
		sayi=sayi/10;
		toplam+=i;
	}
	if(harsald%(toplam+sayi)==0)
		printf("%d harsald sayisidir",harsald);
	else	
		printf("%d harsald sayisi degildir",harsald); 
	return 0;
}
