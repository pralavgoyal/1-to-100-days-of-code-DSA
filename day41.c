// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{int data;struct node* next;};
struct node *front=NULL,*rear=NULL;

void enqueue(int x){
struct node* n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->next=NULL;
if(rear==NULL){front=rear=n;}
else{rear->next=n;rear=n;}
}

void dequeue(){
if(front==NULL){printf("-1\n");return;}
struct node* t=front;
printf("%d\n",t->data);
front=front->next;
if(front==NULL) rear=NULL;
free(t);
}

int main(){
int N,x;
char op[10];
scanf("%d",&N);
for(int i=0;i<N;i++){
scanf("%s",op);
if(strcmp(op,"enqueue")==0){scanf("%d",&x);enqueue(x);}
else if(strcmp(op,"dequeue")==0) dequeue();
}
return 0;
}

