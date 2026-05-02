// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

// Input:
// - First line: an integer n

// Output:
// - Print the integer square root of n

#include<stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);

    long long l=0,r=n,ans=0;

    while(l<=r){
        long long m=l+(r-l)/2;

        if(m*m<=n){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    printf("%lld",ans);
    return 0;
}