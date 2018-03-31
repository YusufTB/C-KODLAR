#include<stdio.h>
#include<stdlib.h>

struct stack{
	int x;
	struct stack *next;
};

typedef struct stack stack;

stack *p;
stack *temp;

void push(int deger){
	temp=(stack*)malloc(sizeof(stack));
	temp->x=deger;
	temp->next=p;
	p=temp;
}
int pop(){
	if(p==NULL){
		printf("stack Bos");
		
		exit(0);
	}
	int deger;
	deger=p->x;
	temp=p;
	p=p->next;
	free(temp);
	
	return deger;
}
stack* peek(){
	return p->x;
}

void isempty(){
	if(p==NULL){
		printf("stack bos\n");
	}
	else{
		printf("stack de deger var\n");
	}
}
	


int main(){
	p=(stack*)malloc(sizeof(stack));
	p=NULL;
	isempty();
	push(10);
	push(20);
	push(30);
	push(40);
	isempty();
	printf("%d(peek)\n",peek());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",peek());
	isempty();
	
	return 0;
}
