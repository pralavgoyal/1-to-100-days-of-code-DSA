// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

#include <stdio.h>
#include <stdlib.h>
struct node{int data;struct node* next;};
struct node *front=NULL,*rear=NULL;
void enqueue(int x){
struct node* n=(struct node*)malloc(sizeof(struct node));
n->data=x;
if(front==NULL){
front=rear=n;
n->next=n;
}else{
n->next=front;
rear->next=n;
rear=n;
}
}
void dequeue(){
if(front==NULL) return;
if(front==rear){
free(front);
front=rear=NULL;
}else{
struct node* t=front;
front=front->next;
rear->next=front;
free(t);
}
}
void display(){
if(front==NULL) return;
struct node* temp=front;
do{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=front);
}
int main(){
int n,m,x;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&x);
enqueue(x);
}
scanf("%d",&m);
for(int i=0;i<m;i++) dequeue();
display();
return 0;
}