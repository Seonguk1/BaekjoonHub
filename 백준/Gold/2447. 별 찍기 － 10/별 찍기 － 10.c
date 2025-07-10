#include <stdio.h>

char arr[3000][3000];

void pattern (int n, int x, int y, int c){
    if(n==1){
        if(c) arr[y][x] = '*';
        else arr[y][x] = ' ';
    }
    else{
        for(int i=y;i<n+y;i+=n/3){
            for(int j=x;j<n+x;j+=n/3){
                if(i == y+n/3 && j == x+n/3) pattern(n/3,j,i,0);
                else pattern(n/3,j,i,c);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    pattern(n, 0, 0, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}