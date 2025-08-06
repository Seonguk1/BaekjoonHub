#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a, const void* b){
    return *(int*)a - *(int*)b;
}

int main() {
    int n,m;
    int arr[100001]={0,};
    int top=0, maxVal = -1000;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        if(m > maxVal) maxVal = m;
        if(m >= 0){
            arr[top] += m;
            if(arr[top] > maxVal) maxVal = arr[top];
        }
        else{
            if(-m <= arr[top]){
                if(arr[top] > maxVal) maxVal = arr[top];
                arr[top] += m;
            }
            else top++;
        }
    }
    // if(arr[top] > maxVal) maxVal = arr[top];
    // qsort(arr, top+1, sizeof(int), cmp);
    printf("%d", maxVal);
    return 0;
}