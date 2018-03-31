#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
	int cnt;
};

typedef struct node node;
typedef struct queue queue;

queue *q;
node *temp;

void enqueue(int deger){
	
	if(q->cnt==0){
		temp=(node*)malloc(sizeof(node));
		temp->x=deger;
		q->front=q->rear=temp;
	}
	else{
		temp=(node*)malloc(sizeof(node));
		temp->x=deger;
		q->rear->next=temp;
		q->rear=temp;
	}
	q->cnt++;
}

int dequeue(){
	if(q->cnt==0){
		printf("queue bos\n");
		return;
	}
	int deger;
	deger=q->front->x;
	q->front=q->front->next;
	q->cnt--;
	return deger;
}
int main(){
	q=(queue*)malloc(sizeof(queue));
	q->front=q->rear=NULL;
	q->cnt=0;	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	enqueue(10);
	enqueue(20);
	printf("%d\n",dequeue());
	
	return 0;
}
