#include <stdio.h>

int arr[500001], n,K,c=0,isPossible=0;

void mergeSort(int left, int right){
    if(left >= right) return ;
    int mid = (left + right) / 2;
    mergeSort(left,mid);
    mergeSort(mid+1, right);

    int L_length = mid-left+1;
    int R_length = right-mid;
    int L[L_length];
    int R[R_length];
    for(int i=0;i<L_length;i++) L[i] = arr[left+i];
    for(int i=0;i<R_length;i++) R[i] = arr[mid+1+i];

    int i=0,j=0,k=left;
    while(i<L_length && j<R_length){
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        c++;
        if(c==K){
            printf("%d",arr[k-1]);
            isPossible=1;
            return;  
        }
    }
    while(i<L_length){
        arr[k++] = L[i++];
        c++;
        if(c==K){
            printf("%d",arr[k-1]);
            isPossible=1;
            return;  
        }
    }
    while(j<R_length){
        arr[k++] = R[j++];
        c++;
        if(c==K){
            printf("%d",arr[k-1]);
            isPossible=1;
            return;  
        }
    }
}

int main() {
    scanf("%d %d",&n, &K);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    mergeSort(0,n-1);
    if(!isPossible) printf("-1");
    return 0;
}