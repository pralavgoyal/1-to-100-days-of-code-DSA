// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{int data;struct node* next;};
struct node* top=NULL;

void push(int x){
struct node* n=(struct node*)malloc(sizeof(struct node));
n->data=x;
n->next=top;
top=n;
}

int pop(){
int x=top->data;
struct node* t=top;
top=top->next;
free(t);
return x;
}

int main(){
char exp[100];
fgets(exp,100,stdin);
char* token=strtok(exp," ");
while(token!=NULL){
if(isdigit(token[0])) push(atoi(token));
else{
int b=pop();
int a=pop();
if(token[0]=='+') push(a+b);
else if(token[0]=='-') push(a-b);
else if(token[0]=='*') push(a*b);
else if(token[0]=='/') push(a/b);
}
token=strtok(NULL," ");
}
printf("%d",pop());
return 0;
}