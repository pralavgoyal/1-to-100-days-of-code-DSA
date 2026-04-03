// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top=-1;
void push(char x){stack[++top]=x;}
char pop(){return stack[top--];}
char peek(){return stack[top];}
int prec(char x){
if(x=='+'||x=='-') return 1;
if(x=='*'||x=='/') return 2;
if(x=='^') return 3;
return 0;
}
int main(){
char infix[100],postfix[100];
int j=0;
scanf("%s",infix);
for(int i=0;i<strlen(infix);i++){
char ch=infix[i];
if(isalnum(ch)) postfix[j++]=ch;
else if(ch=='(') push(ch);
else if(ch==')'){
while(top!=-1&&peek()!='(') postfix[j++]=pop();
pop();
}
else{
while(top!=-1&&prec(peek())>=prec(ch)) postfix[j++]=pop();
push(ch);
}
}
while(top!=-1) postfix[j++]=pop();
postfix[j]='\0';
printf("%s",postfix);
return 0;
}