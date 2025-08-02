#include <stdio.h>
#include <stdlib.h>
typedef struct Card{
    int value;
    int count;
} Card;

int arr[500001];
Card card[500001];
int n,m,x,k=0;

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int search(int x){
    int left = 0, right = k;
    while(left <= right){
        int mid = (left+right)/2;
        if(x == card[mid].value) return card[mid].count;
        else if(x > card[mid].value) left = mid+1;
        else right = mid-1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for(int k=0;k<n;k++){
        scanf("%d",&x);
        arr[k]=x;
    }

    qsort(arr, n, sizeof(int), cmp);

    int i=1, start = 0;
    card[0].value = arr[0];
    card[0].count = 1;
    while(i<n){
        if(arr[i-1] == arr[i]){
            card[k].count++;
        }
        else{
            card[++k].value = arr[i];
            card[k].count = 1;
        }
        i++;
    }
    
    scanf("%d",&m);
    while(m--){
        scanf("%d",&x);
        printf("%d ", search(x));
    }
    
    return 0;
} 