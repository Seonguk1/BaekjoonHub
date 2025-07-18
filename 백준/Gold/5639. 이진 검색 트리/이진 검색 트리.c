// 맨 처음 노드 : 루트 노드
// 큰 노드가 올 때까지 반복 -> 왼쪽 노드로 받음

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int value){
    if(root==NULL) return createNode(value);
    if(value > root->value){
        root->right = insert(root->right, value);
    }
    else{
        root->left = insert(root->left, value);
    }
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    printf("%d\n", root->value);
}

int main(){
    int n;
    if(scanf("%d",&n)==EOF) return 0;
    Node* root = createNode(n);
    Node* cur = root;
    
    while(scanf("%d",&n) != EOF){
        insert(root, n);
    }
    preorder(root);
}