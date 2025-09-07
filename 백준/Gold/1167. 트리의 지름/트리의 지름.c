#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int index;
    int weight;
    struct Node* next;
} Node;

Node* graph[100001];
int visited[100001];
int a,v,u,w;
int far_node;  
int max_dist;

void dfs(int n, int length){
    visited[n] = 1;
    if(length > max_dist){
        max_dist = length;
        far_node = n;
    }
    Node* cur = graph[n];
    while(cur != NULL){
        if(!visited[cur->index]){
            dfs(cur->index, length + cur->weight);
        }
        cur = cur->next;
    }
}

int main() {
    scanf("%d",&v);
    
    for(int i=1;i<=v;i++){
        scanf("%d",&a);
        while(1){
            scanf("%d",&u);
            if(u==-1) break;
            scanf("%d",&w);
            Node* node1 = (Node*)malloc(sizeof(Node));
            node1->index = u;
            node1->weight = w;
            node1->next = graph[a];
            graph[a] = node1;
        }
    }
    
    dfs(1,0);
    for(int i=1;i<=v;i++){visited[i]=0;}
    dfs(far_node,0);
    printf("%d", max_dist);
    
    return 0;
}