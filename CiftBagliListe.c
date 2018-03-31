#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
	struct node *prev;
};

typedef struct node node;

node* creatlist();
void showlist(node*);
node* addvalue(node*);

int main(){
	node *head;
	head=creatlist();
	showlist(head);
	head=addvalue(head);
	showlist(head);
	
	return 0;
}

node* creatlist(){
	int n,i;
	node *head;
	node *p;
	node *q;
	printf("kac eleman gireceksiniz :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i==0){
			head=(node*)malloc(sizeof(node));
			head->prev=NULL;
			p=head;
		}
		else{
			q=p;
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
			p->prev=q;
		}
		printf("%d inci elemanin degerini giriniz:\n",i+1);
		scanf("%d",&p->x);
	}
	p->next=NULL;
	
	return head;
}

void showlist(node *haydar){
	int i=1;
	node *p;
	p=haydar;
	while(p->next!=NULL){
		printf("%d inci elemanin degeri %d dir.\n",i,p->x);
		p=p->next;
		i++;
	}
	printf("%d inci elemanin degeri %d dir.\n",i,p->x);
	printf("\n");
	while(p->prev!=NULL){
		printf("%d inci elemanin degeri %d dir.\n",i,p->x);
		p=p->prev;
		i--;
	}
	printf("%d inci elemanin degeri %d dir.\n",i,p->x);
}
node* addvalue(node *head){
	int n;
	node *p;
	node *q;
	node *temp;
	printf("nereye eklensin 1-0-2\n");
	scanf("%d",&n);
	temp=(node*)malloc(sizeof(node));
	printf("degeri giriniz:\n");
	scanf("%d",&temp->x);
	if(n==1){
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=temp;
	}
	if(n==2){
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		temp->next=NULL;
	}
	if(n==0){
		int i;
		p=head;
		printf("kacinci dugumden sonra eklensin:\n");
		scanf("%d",&n);
		for(i=1;i<n;i++){
			p=p->next;
		}
		temp->next=p->next;
		temp->prev=p;
		p->next->prev=temp;
		p->next=temp;
	}
	
	return head;
}
