#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	int i,j,k=0,A[100];
	srand(time(NULL));
	for(i=0;i<100;i++){
	A[i]=rand()%30;
	}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			 if(A[i]==A[j]&&A[i]!=-1&&A[j]!=-1&&i!=j){
				k++;
				A[j]=-1;
			}
		}
		if(A[i]>=0)
		printf("%d den %d tane var\n",A[i],k+1);
		k=0;
	}
getch();
return 0;
}
	
