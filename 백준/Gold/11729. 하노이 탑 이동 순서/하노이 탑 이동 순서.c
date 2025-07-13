// n이 홀 -> 3으로 이동, 짝 -> 2로 이동 

// i) n = 3
// f(3) -> f(2) -> f(1) -> f(2)

#include<stdio.h>

int arr[2000000][2];
int top=-1;

void f(int n, int cur, int tar){
    if(n==1){
        arr[++top][0]= cur;
        arr[top][1] = tar;
    }else{
        f(n-1,cur,6-cur-tar);    
        arr[++top][0]= cur;
        arr[top][1] = tar;
        f(n-1,6-cur-tar,tar);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    f(n, 1, 3);
    printf("%d\n", top+1);
    for(int i=0;i<=top;i++){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
}