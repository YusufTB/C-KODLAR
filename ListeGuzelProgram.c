#include <stdio.h>
#include <stdlib.h>

struct student{
	int no;
	char name[40];
	int age;
	struct student *next;
};
typedef struct student node;

node *delete_node(node*); //ortadan silme
node *add_node(node*); //Basa ekleme
void showlist(node*);

node* createList(){
	int n,k;
	node *head,*p;
	printf("How many students in the list?");
	scanf("%d",&n);
	for(k=0;k<n;k++){
		if(k==0){
			head = (node *)malloc(sizeof(node));
			p = head;
		}
		else{
			p->next = (node *) malloc(sizeof(node));
			p = p->next;
		}
		printf("Enter %d. student number: ",k+1); scanf("%d",&p->no);
		printf("Enter %d. student name: ",k+1); scanf("%s",p->name);
		printf("Enter %d. student age: ",k+1); scanf("%d",&p->age);
	}
	p->next = NULL;	
	return head;
}

int main(void)
{
	node *head;
	int selection=0;	
	while(1)
	{
		printf("\n1.Create List 2.Delete Node (in middle) 3.Showlist 4.Add node (in head) 5.Exit\n");
		printf("Selection [1-4]?");
		scanf("%d",&selection);
		switch(selection)
		{
		case 1: head = createList();
				break;
		case 2: head=delete_node(head);
				break;
		case 3: showlist(head);
				break;
		case 4: head=add_node(head);
				break;
		case 5: exit(0);
		
		}
	}
}
node *delete_node(node *head){
	node *p,*q;
	int i=0,k=0;
	p=head;
	while(p!=NULL){
		p=p->next;
		i++;
	}
	k=i;
	k=k/2;
	p=head;
	for(i=1;i<=k;i++){
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
	return head;
}
void showlist(node *head){
	node *p;
	int i=1;
	p=head;
	while(p!=NULL){
		printf("%d.ogrencinin ; Nosu :%d Ýsmi: %s Yasi: %d\n",i,p->no,p->name,p->age);
		i++;
		p=p->next;
	}
}
node *add_node(node *head){
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("Basa eklenecek elemanin no sunu giriniz:\n"); scanf("%d",&p->no);
	printf("Basa eklenecek elemanin ismini giriniz:\n"); scanf("%s",p->name);
	printf("Basa eklenecek elemanin yasini giriniz:\n"); scanf("%d",&p->age);
	p->next=head;
	head=p;
	
	return head;
}
