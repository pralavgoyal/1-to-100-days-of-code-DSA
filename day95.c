// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.

#include<stdio.h>
#include<stdlib.h>

struct node{
    float val;
    struct node* next;
};

void insert(struct node** head,float x){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->val=x;
    t->next=NULL;

    if(*head==NULL || (*head)->val>=x){
        t->next=*head;
        *head=t;
        return;
    }

    struct node* cur=*head;
    while(cur->next && cur->next->val<x){
        cur=cur->next;
    }

    t->next=cur->next;
    cur->next=t;
}

int main(){
    int n;
    scanf("%d",&n);

    float a[1000];
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }

    struct node* b[1000];
    for(int i=0;i<n;i++) b[i]=NULL;

    for(int i=0;i<n;i++){
        int idx=(int)(n*a[i]);
        insert(&b[idx],a[i]);
    }

    int k=0;
    for(int i=0;i<n;i++){
        struct node* cur=b[i];
        while(cur){
            a[k++]=cur->val;
            cur=cur->next;
        }
    }
    for(int i=0;i<n;i++){
        printf("%.2f ",a[i]);
    }
    return 0;
}