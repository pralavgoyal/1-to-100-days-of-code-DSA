// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

#include<stdio.h>

int main(){
    int n,i;
    int a[100];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter level order:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int flag=1;

    for(i=0;i<n;i++){
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && a[i]>a[left]){
            flag=0;
            break;
        }
        if(right<n && a[i]>a[right]){
            flag=0;
            break;
        }
    }

    if(flag) printf("YES");
    else printf("NO");

    return 0;
}