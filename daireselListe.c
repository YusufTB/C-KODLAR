#include<stdio.h>
#include<stdlib.h>


struct node{
	int x;
	struct node *next;
};

typedef struct node node;

node* creatlist();
void showlist(node*);

int main(){
	node *head;
	head=creatlist();
	showlist(head);
}

node* creatlist(){
	int n,i;
	node *p;
	node *head;
	printf("kac eleman gireceksiniz:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i==0){
			head=(node*)malloc(sizeof(node));
			p=head;
		}
		else{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		}
		printf("%d inci elemani giriniz:\n",i+1);
		scanf("%d",&p->x);
	}
	p->next=head;
	return head;
}

void showlist(node *head){
	int i=0;
	node *p;
	p=head;
	printf("%d inci deger %d\n",i+1,p->x);
		p=p->next;
	while(p!=head){
		i++;
		printf("%d inci deger %d\n",i+1,p->x);
		p=p->next;
	}
}
