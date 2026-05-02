// Problem Statement
// Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

// This is an optimization problem where binary search on the answer is required.

// Input Format
// n k
// n space-separated integers representing stall positions

// Output Format
// Print the maximum possible minimum distance between any two cows.

#include<stdio.h>

void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int can(int a[],int n,int k,int d){
    int count=1,last=a[0];

    for(int i=1;i<n;i++){
        if(a[i]-last>=d){
            count++;
            last=a[i];
        }
        if(count>=k) return 1;
    }
    return 0;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,n);

    int l=1,r=a[n-1]-a[0],ans=0;

    while(l<=r){
        int m=l+(r-l)/2;

        if(can(a,n,k,m)){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }

    printf("%d",ans);
    return 0;
}