#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
};

typedef struct node node;

node *head;
node *p;
node *q;
int i=0;



void push(int deger){
	if(i==0){
		head=(int*)malloc(sizeof(int));
		p=head;
	}
	else{
		p->next=(int*)malloc(sizeof(int));
		p=p->next;
	}
	p->x=deger;
	p->next=NULL;
	i++;
	
}
int pop(){
	int deger;
	p=head;
	while(p->next!=NULL){
		q=p;
		p=p->next;
	}
	deger=p->x;
	q->next=NULL;
	free(p);
	i--;
	return deger;
}
void isEmpty(){
	printf("%s\n",(i==0)?"Liste bos":"Liste dolu");
}
int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	push(10);
	isEmpty();
	printf("%d\n",pop());
	isEmpty();
	
	return 0;
}
