#include<stdio.h>

typedef struct Heap{
    unsigned int data[100001];
    int size;
} Heap;

// ★ 지정 초기화
Heap heap = {.size = -1};

void swap(unsigned int* a, unsigned int* b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(unsigned int n){
    if(heap.size==-1) heap.data[++heap.size] = n;
    else{
        heap.data[++heap.size] = n;
        int i = heap.size;
        while(i>0){
            int parent = (i-1)/2;
            if(heap.data[i] < heap.data[parent]) swap(&heap.data[parent], &heap.data[i]);
            else break;
            i = (i-1)/2;    
        }
    }
}

unsigned int delete(){
    if(heap.size==-1) return 0;
    unsigned int temp = heap.data[0];
    heap.data[0] = heap.data[heap.size--];
    int i=0;
    while(i<=heap.size){
        int min = i;
        if(i*2+1 <= heap.size && heap.data[i*2+1] < heap.data[min]){
            min = i*2+1;
        }
        if (i*2+2 <= heap.size && heap.data[i*2+2] < heap.data[min]){
            min = i*2+2;
        }
        if(min == i){
            break;
        }
        swap(&heap.data[min], &heap.data[i]);
        i = min;
    }
    return temp;
}

int main(){
    unsigned int t,n;
    scanf("%u", &t);
    while(t--){
        scanf("%u", &n);
        if(!n) printf("%u\n", delete());
        else insert(n);
    }
}