#include<stdio.h>
int main(){
	int sayi,i,j=0,dizi[10];
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	while(sayi>=10){
		i=sayi%10;
		dizi[j]=i;
		j++;
		sayi=sayi/10;
	}
	dizi[j]=sayi;	
	for(i=0;i<=j;i++){
		printf("%d",dizi[i]);
	}
	return 0;	
}









