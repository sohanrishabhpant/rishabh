
#include "functions.h"
void Print(PtrNode Head)
{
    if (Head == NULL)
    {
        return;
    }
    if (Head->NextNode == Head)
    {
        return;
    }
    else
    {
        PtrNode flag = Head->NextNode;

        do
        {
            printf("%d ", flag->Element);
            flag = flag->NextNode;
        } while (flag != Head);
        printf("\n");
    }
}
void Insert(PtrNode Head, int num)
{
    PtrNode temp = malloc(sizeof(node));
    temp->Element = num;
    temp->NextNode = NULL;
    if (Head->NextNode == Head)
    {
        Head->NextNode = temp;
        temp->NextNode = Head;
        return;
    }

    else
    {
        temp->NextNode = Head->NextNode;
        Head->NextNode = temp;
    }
}

PtrNode Find(PtrNode Head, int num)
{
    if (Head->NextNode == Head)
    {
        return NULL;
    }
    else
    {
        PtrNode flag = Head->NextNode->NextNode;
        PtrNode prev = Head->NextNode;
        PtrNode last = Head->NextNode;
        PtrNode tra = Head->NextNode;
        PtrNode start = Head->NextNode;
        PtrNode prev_last = NULL;
        int index=0;
        int flag3;
        while (last->NextNode != Head)
        {
            prev_last = last;
            last = last->NextNode;
        }
        do
        {

            if (tra->Element == num)
            {
                flag3 = 1;
                index++;
                break;
            }
            tra = tra->NextNode;
            index++;
        } while (tra != Head);
        if (flag3 == 0)
        {
            return NULL;
        }
        else
        {
            if (start->Element == num)
            {
                return Head->NextNode;
            }
            else
            {
                if (tra!=last)
                {
                    while (flag->NextNode != Head)
                    {
                        if (flag->Element == num)
                        {
                            prev->NextNode = flag->NextNode;
                            flag->NextNode = Head->NextNode;
                            last->NextNode = Head;
                            Head->NextNode = flag;
                            return Head->NextNode;
                            break;
                        }
                        prev = flag;
                        flag = flag->NextNode;
                    }
                }
                else
                {
                    last->NextNode = Head->NextNode;
                    Head->NextNode = last;
                    prev_last->NextNode = Head;
                    return Head->NextNode;
                }
            }
        }
    }
}