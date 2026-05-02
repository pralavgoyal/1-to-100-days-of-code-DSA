// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

#include<stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int sum(int a[],int n){
    int s=0;
    for(int i=0;i<n;i++) s+=a[i];
    return s;
}

int can(int a[],int n,int m,int mid){
    int students=1,pages=0;

    for(int i=0;i<n;i++){
        if(a[i]>mid) return 0;

        if(pages+a[i] > mid){
            students++;
            pages=a[i];
        }else{
            pages+=a[i];
        }
    }
    return students<=m;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int l=0,r=sum(a,n),ans=r;

    for(int i=0;i<n;i++){
        l=max(l,a[i]);
    }

    while(l<=r){
        int mid=l+(r-l)/2;

        if(can(a,n,m,mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}