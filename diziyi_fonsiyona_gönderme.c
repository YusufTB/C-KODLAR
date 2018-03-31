#include<stdio.h>
void siralama(int A[],int n){
	int i,j,k=0,swap=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i]<A[j]){   
				swap=A[i];
				A[i]=A[j];
				A[j]=swap;
			}
		}
	}
	for(i=0;i<n;i++){
		if(i==n-1)
			printf("%d",A[i]);
		else
			printf("%d<",A[i]);
	}
}
int main(){
	int i,n;
	printf("lutfen dizinin eleman sayisini giriniz:\n");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++){
		printf("lutfen dizinin %d inci elemanini giriniz:\n",i+1);
		scanf("%d",&A[i]);
	}
	siralama(A,n);
	return 0;
}
