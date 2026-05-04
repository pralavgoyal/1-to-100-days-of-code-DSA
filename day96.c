// Problem: Count number of inversions using modified merge sort.
// Inversion if i < j and a[i] > a[j].

#include<stdio.h>

long long merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[1000],R[1000];

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];

    int i=0,j=0,k=l;
    long long inv=0;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k++]=L[i++];
        }else{
            a[k++]=R[j++];
            inv += (n1 - i);
        }
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
    return inv;
}
long long mergeSort(int a[],int l,int r){
    long long inv=0;
    if(l<r){
        int m=l+(r-l)/2;
        inv += mergeSort(a,l,m);
        inv += mergeSort(a,m+1,r);
        inv += merge(a,l,m,r);
    }
    return inv;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long ans = mergeSort(a,0,n-1);
    printf("%lld",ans);
    return 0;
}