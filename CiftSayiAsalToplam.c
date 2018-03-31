#include<stdio.h>
#include<conio.h>
int main()
{
int s,i,j,a;
printf("cift sayi gir:"); scanf("%d",&s);
int B[s];
int t=0;
for(i=2;i<s;i++)
{
	
	for(j=2,a=0;j<i;j++)
	{
		if(i%j==0){
			a++;
		}
		
	}
	if(a==0){
	B[t]=i;
	t++;
	}
}
	int y;
	for(t=0;t<s;t++){
		for(y=0;y<s;y++){
			if(B[t]+B[y]==s){
				printf("%d %d",B[t],B[y]); return 0;
			}
		}
	}
getch();
return 0;

}

/*	if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0) 
	{
	printf("%d\n",i);	
	}
	*/
