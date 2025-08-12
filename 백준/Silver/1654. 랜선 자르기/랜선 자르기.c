#include <stdio.h>

int k,n,arr[10001], max=0;

int main() {
    scanf("%d %d", &k, &n);
    for(int i=0;i<k;i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
    }
    long long left = 0, right = max;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(mid <= 0) break;
        // printf("%d\n",mid);
        int count=0;
        for(int i=0;i<k;i++){
            count += (arr[i]/mid);
        }
        if(count < n){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    printf("%lld",right);
    return 0;
}
// 