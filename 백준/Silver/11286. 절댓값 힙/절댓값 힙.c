#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int data[100001];
    int size;
} Heap;

void insert(Heap *heap, int value){
    heap->data[heap->size] = value;
    int current = heap->size;
    heap->size++;
    while(current > 0){
        int parent = (current-1)/2;
        if(
            ((abs(heap->data[current]) == abs(heap->data[parent])) 
            && heap->data[current] < heap->data[parent])
            || (abs(heap->data[current]) < abs(heap->data[parent]))
            ){
            int temp = heap->data[current];
            heap->data[current] = heap->data[parent];
            heap->data[parent] = temp;
            current = parent;
        }
        else{
            break;
        }
    }
}

int delete(Heap *heap){
    if(heap->size == 0) return 0;
    
    int value = heap->data[0];

    heap->data[0] = heap->data[heap->size-1];
    heap->size--;
    int current = 0;
    while (1) {
        int left_child = 2 * current + 1;
        int right_child = 2 * current + 2;
        int largest = current;

        // 왼쪽 자식과 비교
        if (left_child < heap->size && (
            abs(heap->data[left_child]) < abs(heap->data[largest])
            || (
            abs(heap->data[left_child]) == abs(heap->data[largest]) &&
            heap->data[left_child] < heap->data[largest]
            )
            )) {
            largest = left_child;
        }
        // 오른쪽 자식과 비교
        if (right_child < heap->size && (
            abs(heap->data[right_child]) < abs(heap->data[largest])
            ||(
            abs(heap->data[right_child]) == abs(heap->data[largest]) &&
            heap->data[right_child] < heap->data[largest]
            )
            )) {
            largest = right_child;
        }

        if (largest != current) { // 현재 노드보다 더 큰 자식이 있다면
            // 값 교환
            int temp = heap->data[current];
            heap->data[current] = heap->data[largest];
            heap->data[largest] = temp;
            current = largest; // 현재 노드를 가장 큰 자식으로 이동하여 계속 아래로
        } else {
            break; // 힙 규칙 만족, 멈춤
        }
    }
    
    return value;
}

int main() {
    int n, m;
    scanf("%d", &n);
    Heap heap;
    heap.size = 0;

    for(int i=0;i<n;i++){
        scanf("%d", &m);
        if(m==0){
            printf("%d\n", delete(&heap));
        }
        else{
            insert(&heap, m);
        }
    }
    
    return 0;
}