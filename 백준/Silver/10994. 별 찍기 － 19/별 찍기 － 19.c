#include <stdio.h>
//4 * (n-1) + 1
char arr[500][500];

void f(int n, int a){
    int m = 4*(n-1)+1;
    if(n==1){
        arr[a][a] = '*';
    }
    else{
        f(n-1, a+2);
        for(int i=a;i<a+m;i++){
            arr[a][i]='*';
            arr[a+m-1][i]='*';
            arr[i][a] = '*';
            arr[i][a+m-1]='*';
        }
    }
}

int main(){
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            arr[i][j]=' ';
        }
    }
    
    int n;
    scanf("%d", &n);
    int m = 4*(n-1)+1;
    f(n, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    
}