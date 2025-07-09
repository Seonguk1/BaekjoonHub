#include <stdio.h>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    int row = r2-r1, col = c2-c1, m = (row+1)*(col+1), u=0;
    long long arr[row+1][col+1], n=1;
    long long x = 0, y = 0, i=0, k = 1, c = 0, d=0, max;
    arr[y][x] = 1;
    do{
        if(u==m){
            break;
        } 
        if(x >=c1 && x <= c2 && y >= r1 && y <= r2){
            //printf("%d %d %d\n", x,y,n);
            arr[y-r1][x-c1] = n;
            max = n;
            u++;
        }
        if(d == k){
            i = (i+1)%4;
            d = 0;
            if(c==1){
                k++;
                c=0;  
            } 
            else c=1;
        }
        d++;
        x += dx[i];
        y += dy[i];

    }
    while(n++);

    int count = 1;
    while(1){
        if(max/10 == 0){
            break;
        }
        count++;
        max /= 10;
    }
    
    for(int p=0;p<=row;p++){
        for(int q=0;q<=col;q++){
            printf("%*lld ", count, arr[p][q]);
        }
        printf("\n");
    }
    return 0;
}

