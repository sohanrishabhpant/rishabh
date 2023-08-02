#include"functions.h"
struct stack* init(){
    struct stack*temp=malloc(sizeof (stack));
    temp->top=-1;
    temp->arr=malloc(sizeof (char)*10000);
    return temp;
}
int matchingpair(char ch1,char ch2){
    if ((ch1=='('&&ch2==')')||(ch1=='{'&&ch2=='}')||(ch1=='['&&ch2==']')){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(stack*s){
    if (s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(stack*s){
    if (s->top==10001){
        return 1;
    }
    return 0;
}
void push(stack *s,char val){
if (!isFull(s)){
    s->arr[++s->top]=val;
}
else{
    return ;
}
}
void pop(stack*s){
    if (!isEmpty(s)){
        s->arr[s->top--];
    }
    else{
        return ;
    }
}
char top(const stack*s){
    char val=s->arr[s->top];
    return val;
}
int balanced(char *s){
    stack *head=init();
    int count=0;
    for (int i=0;s[i];i++){
    if (s[i]=='{'|| s[i]=='('|| s[i]=='['){
        push(head,s[i]);
        count++;
    }
    if (s[i]=='}'||s[i]==')'||s[i]==']'&&(count!=0)){
        if (!matchingpair(top(head),s[i])){
            return 0;
        }
        else{
            pop(head);
        }
    }
    if (count==0){
        return 0;
    }
}
if (!isEmpty(head)){
    return 0;
}
else if (isEmpty(head)&&count==0){
    return 0;
}
return 1;

}
int  palindrome(char*s,int n){
    stack *head=init();
    for (int i=0;i<n;i++){
        push(head,s[i]);
    }
    for (int i=0;s[i];i++){
        if (s[i]!=top(head)){
            return 0;
        }
        pop(head);
    }
    return 1;
}

int len(char *temp){
    int count=0;
    for (int i=0;temp[i];i++){
        count++;
    }
    return count;
}