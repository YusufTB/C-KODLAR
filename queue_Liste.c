#include<stdio.h>
#include<stdlib.h>

struct queue{
	int x;
	struct queue *next;
};

typedef struct queue queue;

queue *root;
queue *rear;
queue *temp;
int i=0;




void enqueue(int deger){
	rear->x=deger;
	rear->next=(queue*)malloc(sizeof(queue));
	rear=rear->next;
	i++;
}

int dequeue(){
	if(i==0){
		printf("bos");
		exit(0);
	}
	int deger;
	deger=root->x;
	temp=root;
	root=root->next;
	free(temp);
	i--;
	
	return deger;
}


int main(){
	rear=(queue*)malloc(sizeof(queue));
	root=rear;
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	
	return 0;
	
}
