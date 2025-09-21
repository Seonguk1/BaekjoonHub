#include <stdio.h>

int inorder[100001], postorder[100001], position[100001];
int n;

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];  
    printf("%d ", root);

    int idx = position[root];       
    int leftSize = idx - inStart;   

    preorder(inStart, idx - 1, postStart, postStart + leftSize - 1);
    preorder(idx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    for (int i = 0; i < n; i++) {
        position[inorder[i]] = i;
    }

    preorder(0, n - 1, 0, n - 1);
    return 0;
}
