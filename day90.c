// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.

// Input Format
// n k
// n space-separated integers representing board lengths

// Output Format
// Print the minimum time required to paint all boards.

#include<stdio.h>

int can(int a[],int n,int k,int t){
    int painters=1,sum=0;

    for(int i=0;i<n;i++){
        if(a[i]>t) return 0;

        if(sum+a[i] > t){
            painters++;
            sum=a[i];
        }else{
            sum+=a[i];
        }
    }
    return painters<=k;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(a[i]>l) l=a[i];
        r+=a[i];
    }

    int ans=r;

    while(l<=r){
        int m=l+(r-l)/2;

        if(can(a,n,k,m)){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    printf("%d",ans);
    return 0;
}