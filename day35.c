// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

#include <stdio.h>
#include <stdlib.h>
struct node{int data;struct node* next;};
struct node *front=NULL,*rear=NULL;
void enqueue(int x){
struct node* n=(struct node*)malloc(sizeof(struct node));
n->data=x;
n->next=NULL;
if(rear==NULL){front=rear=n;}
else{rear->next=n;rear=n;}
}
void display(){
struct node* temp=front;
while(temp){
printf("%d ",temp->data);
temp=temp->next;
}
}
int main(){
int n,x;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&x);
enqueue(x);
}
display();
return 0;
}