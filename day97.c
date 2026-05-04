// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
    int* x=(int*)a;
    int* y=(int*)b;
    return x[0]-y[0];
}
void swap(int* a,int* b){
    int t=*a; *a=*b; *b=t;
}
void heapify(int h[],int n,int i){
    int s=i,l=2*i+1,r=2*i+2;
    if(l<n && h[l]<h[s]) s=l;
    if(r<n && h[r]<h[s]) s=r;
    if(s!=i){
        swap(&h[i],&h[s]);
        heapify(h,n,s);
    }
}
void push(int h[],int* n,int x){
    int i=(*n)++;
    h[i]=x;
    while(i>0 && h[(i-1)/2]>h[i]){
        swap(&h[i],&h[(i-1)/2]);
        i=(i-1)/2;
    }
}
int pop(int h[],int* n){
    int t=h[0];
    h[0]=h[--(*n)];
    heapify(h,*n,0);
    return t;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[1000][2];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int heap[1000],sz=0;
    for(int i=0;i<n;i++){
        if(sz>0 && heap[0]<=a[i][0]){
            pop(heap,&sz);
        }
        push(heap,&sz,a[i][1]);
    }
    printf("%d",sz);
    return 0;
}