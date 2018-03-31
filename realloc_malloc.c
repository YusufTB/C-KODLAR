#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *p;
	p=(char*)malloc(5*sizeof(char));
	strcpy(p,"Yusuf");
	printf("%s\n",p);
	p=(char*)realloc(p,1*sizeof(char));
	strcpy(p,"Yusuf Talha Balikcin");
	printf("%s",p);
	free(p);
	return 0;
}
