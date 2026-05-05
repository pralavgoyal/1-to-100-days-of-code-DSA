// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include<stdlib.h>

void merge(int* a,int l,int m,int r,int* idx,int* tmpIdx,int* cnt){
    int i=l,j=m+1,k=l;
    int rightCount=0;
    while(i<=m && j<=r){
        if(a[j] < a[i]){
            tmpIdx[k]=idx[j];
            j++;
            rightCount++;
        }else{
            cnt[idx[i]] += rightCount;
            tmpIdx[k]=idx[i];
            i++;
        }
        k++;
    }
    while(i<=m){
        cnt[idx[i]] += rightCount;
        tmpIdx[k]=idx[i];
        i++; k++;
    }
    while(j<=r){
        tmpIdx[k]=idx[j];
        j++; k++;
    }
    for(int x=l;x<=r;x++){
        idx[x]=tmpIdx[x];
    }
}
void mergeSort(int* a,int l,int r,int* idx,int* tmpIdx,int* cnt){
    if(l>=r) return;
    int m=l+(r-l)/2;
    mergeSort(a,l,m,idx,tmpIdx,cnt);
    mergeSort(a,m+1,r,idx,tmpIdx,cnt);
    merge(a,l,m,r,idx,tmpIdx,cnt);
}
int* countSmaller(int* nums,int n,int* returnSize){
    int* idx=(int*)malloc(n*sizeof(int));
    int* tmpIdx=(int*)malloc(n*sizeof(int));
    int* cnt=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++) idx[i]=i;
    mergeSort(nums,0,n-1,idx,tmpIdx,cnt);
    *returnSize=n;
    return cnt;
}