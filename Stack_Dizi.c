#include<stdio.h>
#include<stdlib.h>


int *dizi;
int boyut=5;
int tepe=0;


void push(int x){
	if(tepe>=boyut){
		dizi=(int*)realloc(dizi,sizeof(int)*boyut*2);
		boyut*=2;
	}
	dizi[tepe++]=x;
}
int pop(){
	if(tepe<=boyut/4){
		dizi=(int*)realloc(dizi,sizeof(int)*boyut/2);
		boyut/=2;
	}
	return dizi[--tepe];
}

int main(){
	dizi=(int*)malloc(boyut*sizeof(int));
	
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
	printf("  %d  ",tepe);
	printf("  %d  ",boyut);
	return 0;
}

