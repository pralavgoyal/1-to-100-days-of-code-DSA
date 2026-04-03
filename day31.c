// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int x){
if(top==MAX-1) printf("Stack Overflow\n");
else stack[++top]=x;
}
void pop(){
if(top==-1) printf("Stack Underflow\n");
else printf("%d\n",stack[top--]);
}
void display(){
if(top==-1) printf("Stack is empty\n");
else{
for(int i=top;i>=0;i--) printf("%d ",stack[i]);
printf("\n");
}
}
int main(){
int n,c,v;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d",&c);
if(c==1){scanf("%d",&v);push(v);}
else if(c==2) pop();
else if(c==3) display();
}
return 0;
}
