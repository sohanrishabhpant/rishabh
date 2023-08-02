
#include "functions.c"

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        char *ch=malloc(sizeof (char)*5);
        scanf("%s",ch);
        char ch1=ch[4];
             char *arr=malloc(sizeof (char)*10000);
    int length;
    int num1;
     int t;
      int norow,nocol;
        switch(ch1){
            case '1':
    scanf("%d",&length);
    scanf("%s",arr);
    int k=len(arr);
    if (length==k){
    reverseString(arr,k);
    }
    for (int i=0;i<k;i++){
        printf("%c",arr[i]);
        if (i==k-1){
            printf("\n");
        }
        
    }
    free(arr);
    break;
    case '2':
    scanf("%d",&num1);
      char *c=malloc(sizeof (char)*10000);
    scanf("%s",c);
    int value=len(c);
    if (value==num1){
    char *var=compressString(c,value);
    // printf("%s\n",var);
    printf("\n");
    free(var);
    }
    break;
    case '3':
           
    scanf("%d",&t);
    int *b=malloc(sizeof (int)*t);
    for (int i=0;i<t;i++){
        scanf("%d",&b[i]);
    }
    int *temp=uniqueElements(b,t);
    for (int i=0;temp[i]!=-1;i++){
        printf("%d ",temp[i]);
    }
    printf("\n");
    // for (int i=0;i<flag;i++){
    //     printf("%d ",temp[i]);
    // }
    free(b);
    break;
    case '4':
    scanf("%d %d",&norow,&nocol);
    int **arr=(int **)malloc (sizeof (int *)*norow);
    for (int i=0;i<norow;i++){
        arr[i]=(int *)malloc(sizeof (int)*nocol);
    }
    for (int i=0;i<norow;i++){
        for (int j=0;j<nocol;j++){
            scanf("%d",&arr[i][j]);
        }
    }
     int **flag1=transpose(arr,norow,nocol);
     for (int i=0;i<nocol;i++){
        for (int j=0;j<norow;j++){
            printf("%d ",flag1[i][j]);
        }printf("\n");
     }
     for (int i=0;i<norow;i++){
        free(arr[i]);
     }
     free(arr);
     for(int i=0;i<nocol;i++){
        free(flag1[i]);
     }
     free(flag1);
     break;
    }
    free(ch);}
}