#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int *arr;
};
struct stack* init(){
    struct stack*temp=malloc(sizeof (struct stack));
    temp->top=-1;
    temp->arr=malloc(sizeof (int)*1000);
    for (int i=0;i<1000;i++){
        temp->arr[i]=0;
    }
    return temp;
}
void push(struct stack*s,int val){
    s->arr[++s->top]=val;
}
int pop(struct stack *s){
    int val=s->arr[s->top--];
    return val;
}
int isempty(struct stack*s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int calPoints(char *operations[1], int operationsSize){
    struct stack*head=init();
    int sum=0;
    for(int i=0;i<operationsSize;i++){
        if (operations[i][0]=='+'){
            int val=pop(head);
            int val1=pop(head);
            int val2=val+val1;
            push(head,val1);
            push(head,val);
            push(head,val2);
        }
        if (operations[i][0]=='C'){
            pop(head);
                 }
        if (operations[i][0]=='D'){
            int val=pop(head);
            int val1=val*2;
            push(head,val);
            push(head,val1);
        }
        else{
            int val=operations[i][0]-'0';
            push(head,val);
        }
        }
    
    int val=isempty(head);
    while (!val){
        sum+=pop(head);
        val=isempty(head);
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    char a[n][1];
    for (int i=0;i<n;i++){
        for (int j=0;j<1;j++){
            scanf("%c",&a[i][j]);
        }
    }
    int sum=calPoints(a,n);
    printf("%d",sum);
}