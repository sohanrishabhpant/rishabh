#include "sort.h"
int max3(int a, int b)
{
    return a >= b ? a : b;
}
int left_child(int i)
{
    return (2 * i) + 1;
}
int right_child(int i)
{
    return (2 * i) + 2;
}
int comp(int a, int b)
{
    if (a >= b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *a, int i, int n)
{
    int left = left_child(i);
    int right = right_child(i);
    int largest = i;
    if (left < n && comp(a[left], a[largest]))
    {
        largest = left;
    }
    if (right < n && comp(a[right], a[largest]))
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, largest, n);
    }
}
void heap_sort(int *a, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    while (n > 0)
    {
        swap(&a[0], &a[n - 1]);
        n = n - 1;
        heapify(a, 0, n);
    }
}
