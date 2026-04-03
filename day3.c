//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

//Input:
//- First line: integer n (array size)
//- Second line: n space-separated integers
//- Third line: integer k (key to search)

#include <stdio.h>

int main() {
    int n, k, i, found = 0, comparisons = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at position %d\n", i + 1);  
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not found\n");
    }

    printf("Comparisons: %d\n", comparisons);

    return 0;
}

