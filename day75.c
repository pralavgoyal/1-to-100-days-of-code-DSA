// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

#include<stdio.h>

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[1000];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0,maxLen=0;
    int hash[20001];
    for(int i=0;i<20001;i++){
        hash[i]=-1;
    }
    hash[10000]=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(hash[sum+10000]!=-1){
            int len=i+1-hash[sum+10000];
            if(len>maxLen){
                maxLen=len;
            }
        }
        else{
            hash[sum+10000]=i+1;
        }
    }
    printf("%d",maxLen);
    return 0;
}