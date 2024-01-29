DFS.c
#include<stdio.h>
#include<stdlib.h>

int G[10][10],n,visited[10];
void DFS(int);

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix of the graph: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("\n");
    DFS(3);
    return 0;
}

void DFS(int i){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<n;j++){
        if(G[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}