
#include "functions.h"
void swap(char *a,char*b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void reverseString (char *str,int length){
    for (int i=0;i<length/2;i++){
        swap(&str[i],&str[length-1-i]);
    }
}
int len(char* a){
    int count=0;
    for (int i=0;a[i];i++){
        count++;
    }
    return count;
}
char * compressString(char *str,int length){
    char *temp=malloc (sizeof (char)* 100000);
     int index;
    int count2;
    int value=0;
    if(str==NULL){
        return NULL;
    }
    else{
    for (int i=0;str[i];i+=index+1){
        count2=1;
        index=0;
     for (int j=i+1;str[j]==str[i];j++){
                index++;
                count2++;
            }
    printf("%c",str[i]);
    printf("%d",count2);
    }
    temp[value]='\0';
   return temp;
   }
   }

   int ** transpose (int **matrix,int NumRow,int NumCol){
    int **tra_matrix=(int**)malloc(sizeof (int*)*NumCol);
    for (int i=0;i<NumCol;i++){
        tra_matrix[i]=(int*)malloc(sizeof (int)*NumRow);
            }
    for (int i=0;i<NumRow;i++){
        for (int j=0;j<NumCol;j++){
            tra_matrix[j][i]=matrix[i][j];
        }
    }return tra_matrix;
   }
    int *uniqueElements(int *arr,int length){
  int *fix=malloc(sizeof (int)*length);
    int *new_arr=malloc(sizeof (int)*10000);
    for (int i=0;i<length;i++){
        fix[arr[i]]=-1;
    }
    int count=0;
    int cre=0;
    for (int i=0;i<length;i++){
        if (fix[arr[i]]==-1){
            fix[arr[i]]=1;
            new_arr[cre]=arr[i];
            count++;
            cre++;
        }
    }new_arr[cre]=-1;
    return new_arr;}