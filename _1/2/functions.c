#include "functions.h"
int min1(int a,int b){
    return a>b? b:a;
}
int max1(int a,int b){
    return a>b?a:b;
}
int dismaxmin(int *arr,int lenArr){
int dis=0;
    int max=0;
    int min;
    int findex=0;
   int dist=1;
    for (int i=1;i<lenArr;i++){
        if (arr[findex]>arr[i]){
            dist=0;
            break;
        }
    }
    if (dist){
        dis++;
    }
    for (int i=1;i<lenArr-1;i++){
        min=999999;
        max=max1(arr[i-1],max);
       for (int j=i+1;j<lenArr;j++){
        min=min1(arr[j],min);
       }
    if (arr[i]>max&&arr[i]<min){
        dis++;
    }
    }
  
    int lindex=lenArr-1;
    int check=1;
    for (int i=0;i<lenArr-1;i++){
        if (arr[i]>arr[lindex]){
            check=0;
            break;
        }
    }
    if (check){
        dis++;
    }
      if (dis==0){
        return 1;
    }
    return dis;
}
//oper5
int *maxMin(int *arr,int lenArr){
    int dis=0;
    int max=0;
    int min;
    int findex=0;
    int dist=1;
    for (int i=1;i<lenArr;i++){
        if (arr[findex]>arr[i]){
            dist=0;
            break;
        }
    }
    if (dist){
        dis++;
    }
    for (int i=1;i<lenArr-1;i++){
        min=+999999;
        max=max1(arr[i-1],max);
       for (int j=i+1;j<lenArr;j++){
        min=min1(arr[j],min);
       }
    if (arr[i]>max&&arr[i]<min){
        dis++;
    }
    }
    int lind=lenArr-1;
    int stop=1;
    for (int i=0;i<lenArr-1;i++){
        if (arr[i]>arr[lind]){
            stop=0;
            break;
        }
    }
    if (stop){
        dis++;
    }

    int *temp=malloc(sizeof (int)*dis);
    int z=0;
    int min2;
    int max2=0;
    int dist2=1;
    for (int i=1;i<lenArr;i++){
        if (arr[findex]>arr[i]){
            dist2=0;
            break;
        }
    }
    if (dist2){
        temp[z++]=findex;
    }
     for (int i=1;i<lenArr-1;i++){
        min2=999999;
        max2=max1(arr[i-1],max2);
       for (int j=i+1;j<lenArr;j++){
        min2=min1(arr[j],min2);
       }
    if ((arr[i]>max2)&&(arr[i]<min2)){
         temp[z]=i;
         z++;
    }
    }
   int lindex=lenArr-1;
int flag=1;
            for(int j=0;j<lenArr-1;j++){
                if (arr[lindex]<arr[j]){
                    flag=1;
                    break;
                }
                else{
                    flag=0;
                }
        }
       
        if (flag==0){
            temp[z]=lindex;
            z++;
            return temp;
            }
    
        
    if (z==0){
        int *p=malloc(sizeof (int)*1);
        p[0]=-1;
        return p;
    }
     else  {
            return temp;
        }
    free(arr);

}

int len(const char*str){
    int count=0;
    for (int i=0;str[i];i++){
        count++;
    }
    return count;
}
int countCharOccurences(const char *str,int length,char ch){
    int count=0;
    for (int i=0;i<length;i++){
        if (ch==str[i]){
            count++;
        }
    }
    return count;
}

int totintersectionArray(int *arr1,int *arr2,int lenArr1,int lenArr2){
    int count=0;
    if (lenArr2<lenArr1){
            int i=0;
           
        for (int j=0;j<lenArr1;j++){
             if (i==lenArr2){
                break;
            }
            if (arr2[i]==arr1[j]){
                i++;
                count++;
            }
            else{
            i++;
        }}
        }
        else{
            int i=0;
        for (int j=0;j<lenArr2;j++){
            if (i==lenArr1){
                break;
                }
            if (arr1[i]==arr2[j]){
                count++;
                i++;
            }
            else{
            i++;
        }}
        

        }

        // else{
        //     for (int i=0;i<lenArr1;i++){
        //         if (arr1[i]==arr2[j]){
        //             count++;
        //         }
        // }}
       
        if (count==0){
            return 1;
        }
    return count;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//oper1
int *intersectionArray(int *arr1,int *arr2,int lenArr1,int lenArr2){
     int count=0;
     
     if (lenArr2<lenArr1){
        int i=0;
        for (int j=0;j<lenArr1;j++){
            if(i==lenArr2){
                break;
            }
            if (arr2[i]==arr1[j]){
                i++;}}}
    else{
         int i=0;
        for (int j=0;j<lenArr2;j++){
            if(i==lenArr1){
                break;
            }
            if (arr1[i]==arr2[j]){
                i++;
                count++;
            }
            else{
            i++;
            
        }}
    }
    
    int *temp=malloc(sizeof (int)*count);
    int pos=0;
    if (lenArr2<lenArr1){
    int i=0;
        for (int j=0;j<lenArr1;j++){
            if (i==lenArr2){
                break;
            }
            if (arr2[i]==arr1[j]){
                temp[pos]=arr2[i];
                pos++;
                i++;
            }
            else{
                i++;
            }
        }}
        else{
            int i=0;
        for (int j=0;j<lenArr2;j++){
            if (i==lenArr1){
                break;
            }
            if (arr1[i]==arr2[j]){
                temp[pos]=arr1[i];
                pos++;
                i++;
            }
            else{
                i++;
            }
        }}

        
    
    
    if (pos==0){
    int *p=malloc(sizeof (int)*1);
    p[0]=-1;
    return p;
    }
    // else{
    // for (int i=0;i<count;i++){
    //     for (int j=i+1;j<count;j++){
    //         if (temp[i]>temp[j]){
    //             swap(&temp[i],&temp[j]);
    //         }
    //     }
    // }
    return temp;
   
}
int min_dis(char**str,int numstr){
    int min=+99999;
    for (int i=0;i<numstr;i++){
        min=min1(len(str[i]),min);
    }
    return min;
} 

char *findLongestCommonPrefix(char **str,int numStr,int maxLen){
        int min=min_dis(str,numStr);
        int dif=-1;
        int var=99999;
        int min2;
        int flag;
        for (int j=0;j<numStr-1;j++){
            dif=0;
            for (int i=0;i<maxLen;i++){
                if(str[j][i]==str[j+1][i]){
                    dif++;
                }
                if (str[j][i]!=str[j+1][i]){
                    flag=0;
                    break;
                   
                }
                }
                if (dif==0){
                    break;
                }
         min2=min1(dif,var);
                var=dif;
        }
        if (dif==-1){
         return str[0];   
        }
        if (dif==0){
            char *p=malloc(sizeof (char)*1);
            p[0]='A';
            return p;
        }
        else{
     char*temp=malloc(sizeof (char)*min2+1);
     for (int i=0;i<min2;i++){
        temp[i]=str[0][i];
     }temp[min2]='\0';
     return temp;
}}
char findFirstNonRepeatingChar (const char*str ,int length){
    int count=0;
    int flag1;
    for (int i=0;i<length;i++){
        flag1=1;
        for (int j=0;j<i;j++){
            if (str[i]==str[j]){
                flag1=0;
                break;
            }
        }
        if (flag1){
            count++;
        }
    }
    char *p=malloc(sizeof (char)*100001);
    int index=0;
    p[index]=str[0];
    int flag;
    for (int i=1;i<length;i++){
        flag=1;
        for (int j=0;j<i;j++){
            if (str[i]==str[j]){
                flag=0;
                break;
            }
        }
        if (flag){
            index++;
            p[index]=str[i];
        }
    }
    // for (int i=0;p[i];i++){
    //     printf("%c",p[i]);
    // }
    // printf("%d",index);
    int count_dis;
    for (int j=0;j<count;j++){
        count_dis=0;
    for (int i=0;i<length;i++){
        if (p[j]==str[i]){
           count_dis++;
        }
    }
    if (count_dis==1){
        return p[j];
    }
    }
    return ' ';
    
}
char *removeSubstring(char *str,int strlength,const char*substr,int substrlength){
    int freq=0;
    int flag;
    char *extracted=malloc(sizeof (char)*10000);
    for (int i=0;str[i];){
        flag=1;
        if (str[i]==substr[0]){
        flag=0;
           for (int j=0;substr[j];j++){
           if (str[i+j]!=substr[j]){
                flag=1;
                break;
           }
           }}
           if (!flag){
            i+=substrlength;
           }
           
           else{
           
           if (flag){
            extracted[freq]=str[i];
            freq++;
            i++;
           }}}
    if (freq==0){
        char *p=malloc(sizeof (char)*1);
        p[0]=' ';
        return p;
    }
    // for (int i=0;extracted[i];i++){
    //     printf("%c",extracted[i]);
    // }
    return extracted;}