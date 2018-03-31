#include<stdio.h>
int main(){
	int i,ust,j,toplam=0;
	printf("bir ust sinir giriniz:");
	scanf("%d",&ust);
	for(i=2;i<=ust;i++){
		for(j=1;j<i;j++){
			if(i%j==0){
				toplam=toplam+j;
			}
		}
		if(i==toplam){
			printf("%d >>mukemmel sayidir\n",i);
		}
		toplam=0;
	}
	return 0;
}
