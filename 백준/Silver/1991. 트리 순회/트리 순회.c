#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	struct Node* left, *right;
} Node;

Node* createNode(char data){
	if(data == '.') return NULL;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void find(Node* temp, Node* node){
	if(temp == NULL || node == NULL) return;
	if(temp->left != NULL && (temp->left->data == node->data)){
		free(temp->left);
		temp->left = node;
		return;
	}
	else if(temp->right != NULL && (temp->right->data == node->data)){
		free(temp->right);
		temp->right = node;
		return;
	}
	if(temp->left != NULL){
		find(temp->left, node);
	}
	if(temp->right != NULL){
		find(temp->right, node);
	}
}

void preorder(Node* root){
	if(root == NULL) return;
	printf("%c", root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%c", root->data);
	inorder(root->right);
}
void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}

int main(){
	int n;
	char cur, left, right;
	scanf("%d", &n);
	getchar(); 
	scanf("%c %c %c", &cur,&left,&right);
	getchar();
	Node* root = createNode(cur);
	root->left = createNode(left);
	root->right = createNode(right);
	for(int i=1;i<n;i++){
		scanf("%c %c %c", &cur,&left,&right);
		getchar();
		Node* node = createNode(cur);
		node->left = createNode(left);
		node->right = createNode(right);
		
		find(root, node);
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}