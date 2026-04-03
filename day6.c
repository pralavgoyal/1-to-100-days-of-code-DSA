//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

//Input:
//- First line: integer n
//- Second line: n space-separated integers (sorted array)

//Output:
//- Print unique elements only, space-separated

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0) {
        return 0;
    }

    int j = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j - 1]) {
            arr[j] = arr[i];
            j++;
        }
    }

    printf("Unique elements are:\n");
    for(int i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
