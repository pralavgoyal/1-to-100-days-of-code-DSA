// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int i, j;
    int diagonal_sum = 0;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        printf("Primary diagonal not possible");
    } else {
        for(i = 0; i < m; i++) {
            diagonal_sum += matrix[i][i];
        }
        printf("%d", diagonal_sum);
    }

    return 0;
}
