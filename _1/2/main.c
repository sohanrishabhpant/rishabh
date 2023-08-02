
#include"functions.c"
int main(){
    int lenarr1;
    int lenarr2;
    int x;
     int total;
     int len1;
     int n;
     int num;
     int num_str,num_substr;
    scanf("%d",&x);
    for (int i=0;i<x;i++){
        char *arr=malloc(sizeof (char)*6);
        scanf("%s",arr);
        char ch=arr[4];
        switch(ch){
            case '1':
             scanf("%d %d",&lenarr1,&lenarr2);
    int *arr1=malloc(sizeof (int)*lenarr1);
    int *arr2=malloc(sizeof (int)*lenarr2);
    for (int i=0;i<lenarr1;i++){
        scanf("%d",&arr1[i]);
    }
    for (int i=0;i<lenarr2;i++){
        scanf("%d",&arr2[i]);
    }
    int value=totintersectionArray(arr1,arr2,lenarr1,lenarr2);
     int *flag=intersectionArray(arr1,arr2, lenarr1, lenarr2);
    for (int i=0;i<value;i++){
        printf("%d ",flag[i]);
    }
    printf("\n");
       break; 
    
   
   case '2': 
     scanf("%d",&total);
    char *b=malloc (sizeof (char)*10000);
    scanf("%s\n",b);
    char ch;
    scanf("%c",&ch);
    int length=len(b);
    if (total==length){
    int occur=countCharOccurences(b,length,ch);
    printf("%d\n",occur);
    
}
break;
 case '3':
    scanf("%d",&len1);
    char str[10000];
    scanf("%s",str);
    if (len1==len(str)){
    char string =findFirstNonRepeatingChar(str,len1);
    if (string==' '){
        printf("%d\n",-1);
    }
    else{
        printf("%c\n",string);
    }}
    break;
    case '4':
    scanf("%d",&num);
    int *lenstr1=malloc(sizeof (int)*num);
    char **str_cpre=malloc(sizeof (char*)*num);
    for (int i=0;i<num;i++){
        str_cpre[i]=malloc(sizeof(char)*10000);
    }
    for (int i=0;i<num;i++){
        scanf("%d %s",&lenstr1[i],str_cpre[i]);
    }
    int max=0;
    for (int i=0;i<num;i++){
        max=max1((lenstr1[i]),max);
    }
    
    char *s=findLongestCommonPrefix(str_cpre,num,max);
    if (s[0]=='A'){
        printf("%d\n",-1);

    }else{
        printf("%s\n",s);
        }
        break;
    case '5':
    scanf("%d",&n);
    int *arr=malloc(sizeof (int )*n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
      int total1=dismaxmin(arr,n);
    int *twoindex=maxMin(arr,n);
    // printf("%d",total1);
   for (int i=0;i<total1;i++){
    printf("%d ",twoindex[i]);
   }
    printf("\n");
    free(twoindex);
    break;
   
   
    case '6':
        
        scanf("%d %d\n",&num_str,&num_substr);
        char str1[10000];
        scanf("%s",str1);
        char sub_str[10000];
        scanf("%s",sub_str);
        char *rem=removeSubstring(str1,num_str,sub_str,num_substr);
        if (rem[0]==' '){
            printf("%d\n",-1);
        }
        else{
            printf("%s\n",rem);
        }
        break;
}
free(arr);
}}