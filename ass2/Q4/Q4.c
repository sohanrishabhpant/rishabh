#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    long long int data;
    struct node *left;
    struct node *right;
} Node;
typedef struct queue
{
   long long  int *arr;
    long long int capacity;
    long long int front, rear;
    long long int counter;
} queue;
Node *makenode(int val)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
queue *makequeue(int capacity)
{
    
    queue *temp = malloc(sizeof(queue));
    temp->capacity=capacity;
    temp->arr = malloc(sizeof(int) * capacity);
    temp->front = 0;
    temp->rear = -1;
    temp->counter=0;
    return temp;
}
int isfull(queue *head)
{
    if (head->counter==head->capacity){
        return 1;
    }
    return 0;
}
int isempty(queue *head)
{
    if (head->rear == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue(queue *head, int val)
{

    if (!isfull(head))
    {
        head->arr[++head->rear] = val;
        head->counter++;
    }
}
long long int dequeue(queue *head)
{
    int val=-1;
    if (!isempty(head))
    {
        val = head->arr[head->front++];
        head->counter--;
    }
    return val;
}
Node *ListToBST(Node *root, int val)
{
    Node *temp = makenode(val);
    if (root == NULL)
    {
        return temp;
    }
    else
    {
        if (root->data > val)
        {
            root->left = ListToBST(root->left, val);
        }
        else
        {
            root->right = ListToBST(root->right, val);
        }
    }
    return root;
}

Node*  Modifyiedvalue(Node *root,long long int*a,queue *q,long long int *sum)
{
    if (root==NULL){
        return 0;
    }
    else{
        Node*flag=root;
        Modifyiedvalue(root->left,a,q,sum);
        enqueue(q,root->data);
        if (root->data>flag->data){
            enqueue(q,flag->data);
            Modifyiedvalue(flag->left,a,q,sum);
            Modifyiedvalue(flag->right,a,q,sum);
        }
        while(q->counter!=0){
            *sum+=dequeue(q);
        }
        root->data=*sum;
        Modifyiedvalue(root->right,a,q,sum);
        return root;
}
}

long long int totalsum(Node*head){
    if (head==NULL){
        return 0;
    }
    else{
        return totalsum(head->left)+totalsum(head->right)+head->data;
    }

}
  
void printatgivennode(Node*head, int i,int pos){
    
     if (head==NULL){
        return;
    }
    if (pos==i){
        printf("%lld ",head->data);
        return;
    }
   
    else{
        printatgivennode(head->left,i,pos+1);
        printatgivennode(head->right,i,pos+1);
    }
   
}
long long int height(Node*head){
    if (head==NULL){
        return 0;
    }
    long long int ldepth=1+height(head->left);
    long long int rdepth=1+height(head->right);
    if (ldepth>rdepth){
        return ldepth;
    }
    else{
        return rdepth;
    }
}
void printlevel(Node*head,long long int n){
    if (head==NULL){
        return;
    }
    else{
        long long int h=height((head));
        long long int depth;
    for (long long int i=0;i<h;i++){
         depth=0;
        printatgivennode(head,i,depth);
    }
}}



int main()
{
      Node *head = NULL;
    long long int n;
  scanf("%lld", &n);
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        head = ListToBST(head, a[i]);
    }
    queue*q=makequeue(1000000);
    long long int sum=0;
    head=Modifyiedvalue(head,a,q,&sum);
    printlevel(head,n);
    printf("\n");
    long long int val=totalsum(head);
    printf("%lld",val);
    printf("\n");
}
