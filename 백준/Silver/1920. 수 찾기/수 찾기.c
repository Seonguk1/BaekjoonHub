#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void*b){
    return *(int*)a > * (int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main(){
    int n,m,num,arr[100001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),cmp);

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int isFind=0;
        scanf("%d",&num);
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] == num){isFind=1;break;}
            if(num > arr[mid]) left = mid+1;
            else right = mid-1;
        }
        printf("%d\n", isFind);
    }
    return 0;
}