#include <stdio.h>
// 시간 초과 때문에 미리 n의 범위에 해당하는 배열을 만듦
int arr[41][2];

int main() {
    arr[0][0]=1;arr[0][1]=0;
    arr[1][0]=0;arr[1][1]=1;
    
    for(int i=2;i<41;i++){
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    
    int t,n;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d",&n);
        printf("%d %d\n", arr[n][0], arr[n][1]);
    }
    return 0;
}