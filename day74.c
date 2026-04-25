// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

#include<stdio.h>
#include<string.h>

int main(){
    int n;
    char names[100][50];
    printf("Enter number of votes: ");
    scanf("%d",&n);
    printf("Enter names:\n");
    for(int i=0;i<n;i++){
        scanf("%s",names[i]);
    }
    int maxCount=0;
    char winner[50];
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(strcmp(names[i],names[j])==0){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            strcpy(winner,names[i]);
        }
        else if(count == maxCount){
            if(strcmp(names[i],winner) < 0){
                strcpy(winner,names[i]);
            }
        }
    }
    printf("%s %d",winner,maxCount);
    return 0;
}