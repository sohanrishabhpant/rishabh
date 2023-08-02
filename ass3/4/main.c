#include"heap.c"
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    heap *root=create(100000);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        heap_insert(root,a[i]);
    }
    
    heap_sort(root,n);
    permutation(root,b,n,0);
        
}