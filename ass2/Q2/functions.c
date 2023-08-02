#include"functions.h"
int count=0;
qnode *makenode(int val)
{
    qnode *temp = malloc(sizeof(qnode));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
Queue create()
{
    Queue head = malloc(sizeof(struct queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}

void Push(Queue head, int val)
{
    qnode *temp = makenode(val);
    if (head->rear == NULL)
    {
        head->front = temp;
        head->rear = temp;
        head->rear->next = head->front;
        return;
    }
    else
    {
        head->rear->next = temp;
        head->rear = temp;
        temp->next = head->front;
    }
}
int Pop(Queue head)
{
    int count = 0;
    if (head->rear == NULL &&count==0)
    {
        return -1;
    }
    else
    {
        qnode *temp = head->front;
        head->front = head->front->next;

        if (head->front == temp)
        {
            count++;
            int val = temp->data;
            free(temp);
            head->rear = NULL;
            head->front = NULL;
            return val;
        }
        else
        {
            count++;
            head->rear->next = head->front;
            int val = temp->data;
            free(temp);
            return val;
        }
    }
}
void Inject(Queue head, int val)
{
    qnode *temp = makenode(val);
    if (head->rear == NULL)
    {
        head->front = temp;
        head->rear = temp;
        head->rear->next = head->front;
        return;
    }
    else
    {
        temp->next = head->front;
        head->front = temp;
        head->rear->next = head->front;
    }
}
int popRear(Queue head)
{
    if (head->rear == NULL)
    {
        return -1;
    }
    else
    {
        qnode *temp = head->front;
        qnode *flag = head->rear;
        qnode *prev = NULL;
        while (temp != head->rear)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL)
        {
            prev->next = head->front;
            head->rear = prev;
            int val = flag->data;
            free(flag);
            return val;
        }
        else
        {
           int val=temp->data;
            head->rear = NULL;
            head->front = NULL;
            return val;
        }
    }
}

void Print(Queue head)
{
    if (head->rear == NULL)
    {
        printf("-1");
        return;
    }
    else
    {
        qnode *temp = head->front;
        while (temp != head->rear)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}
void PrintReverse(Queue head)
{
    if (head->rear == NULL && count == 0)
    {
        printf("%d", -1);
        return;
    }
    else if (head->rear == NULL)
    {
        return;
    }
    else
    {
        int val = popRear(head);
        count++;
        printf("%d ", val);
        PrintReverse(head);
        Push(head, val);
    }
}
int len(Queue head)
{
    int count = 0;
    qnode *temp = head->front;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head->front);
    return count;
}
int findElem(Queue head, int pos)
{
    if (head->rear == NULL)
    {
        return -1;
    }
    qnode *temp = head->front;
    int count = len(head);
    if (pos > count)
    {
        return -1;
    }
    else
    {
        int val = pos-1;
        while (val)
        {
                temp = temp->next;
                val--;
            }
             return temp->data;
        }
    }


void remKElemes(Queue head, int k)
{
    while (k)
    {
        Pop(head);
        k--;
    }
}