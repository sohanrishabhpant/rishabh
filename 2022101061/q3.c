#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct graph{
    int v;
    int **adj;
    int col;
}graph;
int max(int a,int b){
    return a>b?a:b;
}
graph*create(int r,int c){
    graph*temp=malloc(sizeof (graph));
    temp->v=r;
    temp->col=c;
    temp->adj=malloc(sizeof (int*)*r);
    for (int i=0;i<r;i++){
        temp->adj[i]=malloc(sizeof (int)*c);
        for (int j=0;j<c;j++){
            temp->adj[i][j]=0;
        }
    }
    return temp;
}
int neighbour(graph*temp,int r,int c){
    int count1=0;
    int del_r[]={0,0,1,-1};
    int del_c[]={1,-1,0,0};
    for (int i=0;i<4;i++){
        int new_r=r+del_r[i];
        int new_c=c+del_c[i];
        if (new_r<temp->v&&new_c<temp->col&&new_r>=0&&new_c>=0){
            if (temp->adj[new_r][new_c])
            count1++;
        }
    }
    return 4-count1;
}
void profit(graph*temp,int r,int c,int *totalcount1,int *count1,bool**visited){
    int del_r[]={0,0,1,-1};
    int del_c[]={1,-1,0,0};
    if (r>=0&&c>=0&&r<temp->v&&c<temp->col&&temp->adj[r][c]&&visited[r][c]==false){
        *totalcount1=*totalcount1+1;
        *count1=*count1+neighbour(temp,r,c);
        visited[r][c]=true;
    }
    else{
        return ;
    }

    for (int i=0;i<4;i++){
        int new_r=r+del_r[i];
        int new_c=c+del_c[i];
        if (r<temp->v&&c<temp->col&&r>=0&&c>=0){
            if (temp->adj[r][c]){
                // printf("row:%d col:%d,cou:%d\n",r,c,*count1);
            profit(temp,new_r,new_c,totalcount1,count1,visited);
        }
        else{
            return ;
        }
        }
    }return ; 
}
int traversal(graph*temp){
    int first_row=0;
    int first_column=0;
    int ans=0;
    int total_count=0;
    int count=0;
    bool **visited=malloc(sizeof (bool*)*temp->v);
    for (int i=0;i<temp->v;i++){
        visited[i]=malloc(sizeof (bool)*temp->col);
    }
    for (int i=0;i<temp->v;i++){
        for (int j=0;j<temp->col;j++){
            visited[i][j]=false;
        }
    }
  for (int i=0;i<temp->v;i++){
    for (int j=0;j<temp->col;j++){
        if (temp->adj[i][j]==1){
            first_column=j;
            first_row=i;
            profit(temp,first_row,first_column,&total_count,&count,visited);
            // printf("profit:%d\n",count);
            // printf("total_count:%d\n",total_count);
             if (4*total_count-count>=ans){
                ans=4*total_count-count;
             }
              total_count=0;
                count=0;
           }
    }
  }
      return ans;
    }
int main(){
    int n,m;
     scanf("%d %d",&n,&m);
    int r;
    scanf("%d",&r);
    int r1,c;
    graph*temp=create(n,m);
    for (int i=0;i<r;i++){
    scanf("%d %d",&r1,&c);
    temp->adj[r1-1][c-1]=1;
    }
    // printf("%d\n",temp->adj[0][1]);   

     int ans=traversal(temp);
    printf("%d\n",ans);

}