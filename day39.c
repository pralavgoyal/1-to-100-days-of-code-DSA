// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

#include <stdio.h>
#include <string.h>
#define MAX 1000
int heap[MAX],size=0;

void swap(int*a,int*b){int t=*a;*a=*b;*b=t;}

void heapifyUp(int i){
while(i>0){
int p=(i-1)/2;
if(heap[p]>heap[i]){swap(&heap[p],&heap[i]);i=p;}
else break;
}
}

void heapifyDown(int i){
while(1){
int l=2*i+1,r=2*i+2,sm=i;
if(l<size&&heap[l]<heap[sm]) sm=l;
if(r<size&&heap[r]<heap[sm]) sm=r;
if(sm!=i){swap(&heap[i],&heap[sm]);i=sm;}
else break;
}
}

void insert(int x){
heap[size]=x;
heapifyUp(size);
size++;
}

int extractMin(){
if(size==0) return -1;
int x=heap[0];
heap[0]=heap[size-1];
size--;
heapifyDown(0);
return x;
}

int peek(){
if(size==0) return -1;
return heap[0];
}

int main(){
int N,x;
char op[20];
scanf("%d",&N);
for(int i=0;i<N;i++){
scanf("%s",op);
if(strcmp(op,"insert")==0){scanf("%d",&x);insert(x);}
else if(strcmp(op,"extractMin")==0) printf("%d\n",extractMin());
else if(strcmp(op,"peek")==0) printf("%d\n",peek());
}
return 0;
}