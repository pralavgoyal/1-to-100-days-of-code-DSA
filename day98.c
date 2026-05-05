// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    int* x=(int*)a;
    int* y=(int*)b;
    return x[0]-y[0];
}

int main(){
    int n;
    scanf("%d",&n);
    int a[1000][2];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int s=a[0][0],e=a[0][1];
    for(int i=1;i<n;i++){
        if(a[i][0] <= e){
            if(a[i][1] > e) e=a[i][1];
        }else{
            printf("%d %d\n",s,e);
            s=a[i][0];
            e=a[i][1];
        }
    }
    printf("%d %d",s,e);
    return 0;
}