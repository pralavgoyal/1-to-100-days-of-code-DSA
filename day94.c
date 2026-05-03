// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[1000];
    int mx=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>mx) mx=a[i];
    }
    int *cnt=(int*)calloc(mx+1,sizeof(int));
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<=mx;i++){
        cnt[i]+=cnt[i-1];
    }
    int *out=(int*)malloc(n*sizeof(int));
    for(int i=n-1;i>=0;i--){
        out[--cnt[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",out[i]);
    }
    free(cnt);
    free(out);
    return 0;
}