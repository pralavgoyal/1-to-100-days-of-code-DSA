// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

#include<stdio.h>

#define SIZE 100

int hashTable[SIZE];
int hash(int key,int m){
    return key % m;
}

void insert(int key,int m){
    int i=0;
    int idx;

    while(i<m){
        idx=(hash(key,m)+i*i)%m;

        if(hashTable[idx]==-1){
            hashTable[idx]=key;
            return;
        }
        i++;
    }

    printf("Hash Table Full\n");
}
void search(int key,int m){
    int i=0;
    int idx;
    while(i<m){
        idx=(hash(key,m)+i*i)%m;

        if(hashTable[idx]==key){
            printf("Found\n");
            return;
        }
        if(hashTable[idx]==-1){
            break;
        }
        i++;
    }
    printf("Not Found\n");
}

int main(){
    int m,n,i,choice,key;

    printf("Enter table size: ");
    scanf("%d",&m);

    for(i=0;i<m;i++){
        hashTable[i]=-1;
    }
    printf("Enter number of operations: ");
    scanf("%d",&n);
    printf("1.Insert 2.Search\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&choice,&key);

        if(choice==1){
            insert(key,m);
        }
        else if(choice==2){
            search(key,m);
        }
    }
    return 0;
}