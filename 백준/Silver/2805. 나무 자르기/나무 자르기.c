#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[1000001], max = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
    }
    long long left = 0, right = max, mid, answer;
    while(left <= right){
        mid = (left + right) / 2;
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > mid)
                sum += arr[i] - mid;
        }
        if(sum >= m){
            answer = mid;
            left = mid+1;
        } 
        else right = mid-1;
    }
    printf("%lld", answer);
}