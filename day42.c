// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

#include <stdio.h>
#define MAX 1000
int queue[MAX],front=0,rear=-1;
int stack[MAX],top=-1;

void enqueue(int x){queue[++rear]=x;}
int dequeue(){return queue[front++];}
void push(int x){stack[++top]=x;}
int pop(){return stack[top--];}

int main(){
int n,x;
scanf("%d",&n);
for(int i=0;i<n;i++){scanf("%d",&x);enqueue(x);}
for(int i=0;i<n;i++) push(dequeue());
for(int i=0;i<n;i++) enqueue(pop());
for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
return 0;
}