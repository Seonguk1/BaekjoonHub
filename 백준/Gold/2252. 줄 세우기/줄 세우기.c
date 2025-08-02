#include<stdio.h>
#include<stdlib.h>
#define MAX 32001

typedef struct Node{
    int index;
    struct Node* next;
} Node;

Node* list[MAX];
int n,m;
int edge[MAX]={0,};
int visited[MAX];
int q[MAX];
int front = -1, rear = -1;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        
        Node* node1 = (Node*)malloc(sizeof(Node));
        node1->index = u;
        node1->next = list[v];
        list[v] = node1;
        
        Node* node2 = (Node*)malloc(sizeof(Node));
        node2->index = v;
        node2->next = list[u];
        list[u] = node2;
        
        edge[v]++;
    }

    for(int i=1;i<=n;i++){
        if(edge[i]==0 && !visited[i]){
            visited[i]=1;
            q[++rear] = i;
            if(front==-1) front=0;
        }
    }
    while(front <= rear){
        int popped = q[front++];
        printf("%d ",popped);
        Node* current = list[popped];
        while(current != NULL){
            edge[current->index]--;
            if(edge[current->index]==0){
                q[++rear] = current->index;
            }
            current = current->next;
        }
    }
    
}