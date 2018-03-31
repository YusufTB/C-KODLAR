#include<stdio.h>
int main(){
	int A[5]={-5,40,30,2,10};
	int B[5]={1,13,11,3,33};
	int C[10];
	int D[10];
	int i=0,j=0;
	while(j<5){
		C[i]=A[j];
		i++;
		C[i]=B[j];
		i++;
		j++;
	}
	int min=999999,k=0;
	i=0,j=0;
	for(i;i<10;i++){
		for(j=0;j<10;j++){
			if(C[j]<min){
				min=C[j];
				D[i]=min;
				k=j;
			}
		}
		C[k]=999999;
		min=999999;
	}
	i=0;
	for(i=0;i<10;i++){
		printf("%d<",D[i]);
	}
	
	return 0;
}
