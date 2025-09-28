#include<stdio.h>
#include<stdlib.h>
int n;

typedef struct Node {
    int index;
    int weight;
    struct Node* next;
} Node;

Node* graph[10001];
int visited[10001];
int maxDist = 0, farNode;

void dfs(int cur, int dist){
    visited[cur]=1;
    if (dist > maxDist) {
        maxDist = dist;
        farNode = cur;
    }
    for (Node* p = graph[cur]; p != NULL; p = p->next) {
        if (!visited[p->index]) {
            dfs(p->index, dist + p->weight);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int p,c,w;
        scanf("%d %d %d",&p,&c,&w);
        Node* node1 = malloc(sizeof(Node));
        node1->index = c;
        node1->weight = w;
        node1->next = graph[p];
        graph[p] = node1;

        Node* node2 = malloc(sizeof(Node));
        node2->index = p;
        node2->weight = w;
        node2->next = graph[c];
        graph[c] = node2;
    }
    dfs(1,0);
    
    maxDist=0;
    for(int i = 1; i <= n; i++) visited[i] = 0;
    dfs(farNode, 0);

    printf("%d", maxDist);
}