//Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

//Input:
//- First line: integer p (number of entries in server log 1)
//- Second line: p sorted integers representing arrival times from server 1
//- Third line: integer q (number of entries in server log 2)
//- Fourth line: q sorted integers representing arrival times from server 2)

#include <stdio.h>

int main()
{
    int p, q;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int a[p];
    printf("Enter arrival times for server log 1:\n");
    for(int i = 0; i < p; i++)
        scanf("%d", &a[i]);

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int b[q];
    printf("Enter arrival times for server log 2:\n");
    for(int i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int c[p + q];
    int i = 0, j = 0, k = 0;

    while(i < p && j < q)
    {
        if(a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < p)
        c[k++] = a[i++];

    while(j < q)
        c[k++] = b[j++];

    printf("Merged chronological log:\n");
    for(int i = 0; i < p + q; i++)
        printf("%d ", c[i]);

    return 0;
}
