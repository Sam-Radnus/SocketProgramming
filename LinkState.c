#include<stdio.h>
#include<stdlib.h>
void shortest_path(int n,int cost[n][n],int src)
{
    int dist[n];
    int visited[n];
    int i;
    int last[n];
    int count;
    for(i=0;i<n;i++){
        dist[i]=1000;
        visited[i]=0;
        last[i]=src;
    }
    dist[src]=0;
    for(count=0;count<n-1;count++)
    {
        int min=1000;
        int u=0;
        for(i=0;i<n;i++)
        {
            if(visited[i]=0 && dist[i]<=min)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        for(i=0;i<n;i++){
            if(visited[i]==0 && dist[u]+cost[u][i]<dist[i])
            {
                dist[i]=dist[u]+cost[u][i];
                if(last[i]==src)
                {
                   last[i]=src;
                }
            }
        }
        for(i=0;i<n;i++)
        {
          if(i==src-1)
          {
            printf("\n%d",src+1);
          }
          else{
            if(last[i]==src)
            {
                printf("\n %d %d",i+1,dist[i]);
            }
            else{
                printf("\n %d %d %d",i+1,dist[i],last[i]+1);
            }
          }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i!=src)
        {
            printf("\n The Cost of Shortest Path from router %d to %d is %d \n",src+1,i+1,dist[i]);
        }
    }
}
    int main(){
       int n; 
       int i; 
       int j; 
       int src; 
       printf("Enter the Number of Nodes : "); 
       scanf("%d",&n); 
       int cost[n][n]; 
       printf(" Enter the cost between Nodes : \n"); 
       for(i = 0; i < n ; i++) { 
         for(j = 0 ;j < n ; j++) {   
          if(i != j) {  
             printf("Cost from %d->%d : ",i + 1 ,j + 1); 
             scanf("%d",&cost[i][j]); 
             if(cost[i][j] == 0) { 
             cost[i][j] = 1000; 
                } 
            } 
         else { 
             cost[i][j] = 0; 
             } 
           } 
        } 
        printf(" Enter the source Node : "); 
        scanf("%d",&src); 
 
        printf("Routing Table of Node %d\n",src); 
        printf("Destination\tCost\tNext Hop\n"); 
        for(i = 0; i < n ; i++) { 
          if(i == src - 1) { 
             printf(" %d\t\t-\t\t-\n",src); 
          } 
          else { 
          if(cost[src-1][i] == 0) { 
             printf(" %d\t\t-\t\t- \n",i+1); 
        } 
         else { 
             printf(" %d\t\t%d\t\t-\n",i+1,cost[src-1][i]); 
          } 
      } 
    } 
 
 printf("After Applying Dijkstra's Algorithm\n\n"); 
 
 shortest_path(n , cost , src-1); 
 return 0; 
}