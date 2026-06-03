#include<stdio.h>
#define INF 999
void Dijkastra(int cost[10][10],int n,int start,int d[10]){
      int visited[10]={0},i,j,min,u;
      for(i=1;i<=n;i++)
            d[i]=cost[start][i];
      visited[start]=1;
      for(i=1;i<=n;i++){
            min=INF;
            for(j=1;j<=n;j++)
                  if(!visited[j] && d[j]<min){
                        min=d[j];
                        u=j;
                  }
            visited[u]=1;
            for(j=1;j<=n;j++)
                  if(!visited[j] && d[u]+cost[u][j]<d[j])
                        d[j]=d[u]+cost[u][j];

      }
}
int main(){
      int cost[10][10],d[10],n,start,i,j;
      printf("Enter the number of vertices:");
      scanf("%d",&n);
      printf("Enter the cost matrix:\n");
      for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                  scanf("%d",&cost[i][j]);
      printf("Enter the starting vertex:");
      scanf("%d",&start);
      Dijkastra(cost,n,start,d);
      printf("The shortest distances from vertex %d are:\n",start);
      for(i=1;i<=n;i++)
            printf("To vertex %d: %d\n",i,d[i]);
      return 0;
}