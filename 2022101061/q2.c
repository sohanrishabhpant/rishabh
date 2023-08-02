#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int row_i;
    int col_i;
    short int height;
    int ans;
    struct node *next;
} node;
// typedef struct qnode
// {
//     int data;
//     struct qnode *next;
// } qnode;
typedef struct queue *Queue;
typedef struct queue
{
    node *front;
    node *rear;
} queue;
int count = 0;
node *makenode(int r, int c, int height, int ans)
{
    node *temp = malloc(sizeof(node));
    temp->height = height;
    temp->col_i = c;
    temp->row_i = r;
    temp->ans = ans;
    return temp;
}
Queue create()
{
    Queue head = malloc(sizeof(struct queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}

void Push(Queue head, int r, int c, int height, int ans)
{
    node *temp = makenode(r, c, height, ans);
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
node *Pop(Queue head)
{
    int count = 0;
    if (head->rear == NULL && count == 0)
    {
        return NULL;
    }
    else
    {
        node *temp = head->front;
        head->front = head->front->next;

        if (head->front == temp)
        {
            count++;
            node *val = temp;
            head->rear = NULL;
            head->front = NULL;
            return val;
        }
        else
        {
            count++;
            head->rear->next = head->front;
            node *val = temp;
            return val;
        }
    }
}
void Inject(Queue head, int r, int c, int height, int ans)
{
    node *temp = makenode(r, c, height, ans);
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
node *popRear(Queue head)
{
    if (head->rear == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = head->front;
        node *flag = head->rear;
        node *prev = NULL;
        while (temp != head->rear)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL)
        {
            prev->next = head->front;
            head->rear = prev;
            node *val = flag;
            free(flag);
            return val;
        }
        else
        {
            node *val = temp;
            head->rear = NULL;
            head->front = NULL;
            return val;
        }
    }
}

int total(node **arr, int n, int m)
{
    int count1=0;
    queue *head = create(n);
    
    bool visited[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    arr[0][0].ans = 0;
    Push(head, 0, 0, arr[0][0].height, arr[0][0].ans);
    count1++;
    while (count1 != 0)
    {
        node *ele = Pop(head);
        count1--;
        int i = ele->row_i;
        int j = ele->col_i;

        int del_ro[] = {0, 0, -1, 1};
        int del_col[] = {1, -1, 0, 0};
        // printf("ele_row:%d ele_col:%d ele->height:%d ele->ans:%d\n",ele->row_i,ele->col_i,ele->height,ele->ans);
        if (!visited[i][j])
        {   visited[i][j] = true;
            
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + del_ro[k];
                int new_j = j + del_col[k];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && visited[new_i][new_j] == false)
                {
                    if (ele->height == arr[new_i][new_j].height)
                    {
                        if (ele->ans <= arr[new_i][new_j].ans)
                        {
                            arr[new_i][new_j].ans = ele->ans;
                        }
                        Inject(head, new_i, new_j, arr[new_i][new_j].height, arr[new_i][new_j].ans);
                        count1++;
                    }
                    else
                    {
                        if (ele->ans + 1 <= arr[new_i][new_j].ans)
                        {
                            arr[new_i][new_j].ans = ele->ans + 1;
                        }
                        Push(head, new_i, new_j, arr[new_i][new_j].height, arr[new_i][new_j].ans);
                        count1++;
                    }
                }
            }
            
        }
    }
    return arr[n - 1][m - 1].ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    int n, m;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        short int a[n][m];
        node **arr = (node **)malloc(sizeof(node *) * n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = (node *)malloc(sizeof(node) * m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%hd", &a[i][j]);
                arr[i][j].row_i = i;
                arr[i][j].col_i = j;
                arr[i][j].height = a[i][j];
                arr[i][j].ans = 100000;
            }
        }

        int weight = total(arr, n, m);
        printf("%d\n", weight);
    }
}