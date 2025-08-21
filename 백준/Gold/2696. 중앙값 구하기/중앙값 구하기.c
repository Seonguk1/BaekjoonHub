#include <stdio.h>
#define SIZE 10000

int t,m,n;
int minHeap[SIZE], maxHeap[SIZE];
int sizeMin = -1, sizeMax=-1;

void init(){
    sizeMin = -1;
    sizeMax = -1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushMin(int x){
    minHeap[++sizeMin] = x;
    int cur = sizeMin;
    while(cur > 0){
        int parent = (cur-1)/2;
        if(minHeap[cur] < minHeap[parent]){
            swap(&minHeap[cur], &minHeap[parent]);
            cur = parent;
        }
        else break;
    }
}

void pushMax(int x){
    maxHeap[++sizeMax] = x;
    int cur = sizeMax;
    while(cur > 0){
        int parent = (cur-1)/2;
        if(maxHeap[cur] > maxHeap[parent]){
            swap(&maxHeap[cur], &maxHeap[parent]);
            cur = parent;
        }
        else break;
    }
}

void popMin(){
    if(sizeMin==-1) return;
    swap(&minHeap[0], &minHeap[sizeMin]);
    sizeMin--;
    int cur = 0;
    while(cur < sizeMin){
        int temp = cur;
        int left = cur*2+1;
        int right = cur*2+2;
        if(left <= sizeMin && minHeap[left] < minHeap[temp]) temp = left;
        if(right <= sizeMin && minHeap[right] < minHeap[temp]) temp = right;
        if(temp == cur) break;
        swap(&minHeap[cur], &minHeap[temp]);
        cur = temp;
    }
    
}

void popMax(){
    if(sizeMax==-1) return;
    swap(&maxHeap[0], &maxHeap[sizeMax]);
    sizeMax--;
    int cur = 0;
    while(cur < sizeMax){
        int temp = cur;
        int left = cur*2+1;
        int right = cur*2+2;
        if(left <= sizeMax && maxHeap[left] > maxHeap[temp]) temp = left;
        if(right <= sizeMax && maxHeap[right] > maxHeap[temp]) temp = right;
        if(temp == cur) break;
        swap(&maxHeap[cur], &maxHeap[temp]);
        cur = temp;
    }
    
}

void insert(int x){
    if(sizeMax==-1 || x <= maxHeap[0]) pushMax(x);
    else pushMin(x);

    if(sizeMax > sizeMin + 1){
        pushMin(maxHeap[0]); popMax();
    } else if(sizeMin > sizeMax){
        pushMax(minHeap[0]); popMin();
    }
}


int main(){
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&m);
        printf("%d\n", (m + 1) / 2);
        int c = 0;
        for(int i=1;i<=m;i++){
            scanf("%d",&n);
            insert(n);
            if(i%2==1){
                printf("%d ", maxHeap[0]);
                c++;
                if(c%10==0) printf("\n");
            }
        }
        if(c % 10 != 0) printf("\n");
    }
}