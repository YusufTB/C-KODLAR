#include<stdio.h>
#include<conio.h>

int main(){
	int i=0;
	char k;
	char sifre[20];
	printf("sifrenizi giriniz:");
	while(k!=13){
		k=getch();
		if(k==13){
			printf("\n%s",sifre);
		}
		else{
		putchar('*');
		sifre[i]=k;
		i++;
		}
	}
	return 0;
}
