#include <stdio.h>

int arr[21][21][21];

int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return w(20, 20, 20);

    // 메모이제이션: 이미 계산된 값이 있는지 확인
    if (arr[a][b][c] != -1) {
        return arr[a][b][c]; 
    }
    
    if (a < b && b < c) {
        arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    
    return arr[a][b][c];
}

int main(){
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                arr[i][j][k] = -1;
            }
        }
    }
    int a,b,c;
    while(1){
        scanf("%d %d %d",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    
}