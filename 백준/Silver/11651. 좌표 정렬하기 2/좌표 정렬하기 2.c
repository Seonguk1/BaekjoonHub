#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int* arr2, int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	
	temp = arr2[a];
	arr2[a] = arr2[b];
	arr2[b] = temp;
}

int partition(int arr[], int arr2[], int left, int right) {
    // 랜덤 피벗 적용 -> 이미 정렬된 경우의 n^2 방지 
	int p_idx = left + rand() % (right - left + 1);
    swap(arr, arr2, p_idx, right); 

    int p = right;
    right--;
    while(1){
        while(left <= right && arr[left] <= arr[p]){
        	// 피벗과 값이 같을 때 arr_y 값 비교 
            if(arr[left] == arr[p] && arr2[left] > arr2[p]){
                break;
            }
            left++;	
        } 
        while(left <= right && arr[right] >= arr[p]){
        	// 피벗과 값이 같을 때 arr_y 값 비교
            if(arr[right] == arr[p] && arr2[right] < arr2[p]){
                break;
            }
            right--; 	
        } 
        if(left >= right) break;
        swap(arr, arr2, left, right);
        left++;
        right--; 
    }
    swap(arr, arr2, p, left);
    return left;
}


void quickSort(int arr[], int arr2[], int left, int right){
	if(left < right){
		int pivot = partition(arr, arr2, left, right);
		
		if(pivot == -1) return ;
		
		quickSort(arr, arr2, left, pivot-1);
		quickSort(arr, arr2, pivot+1, right);
	}
}

int main(){
	int n, arr_x[100001], arr_y[100001];
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d", &arr_x[i],&arr_y[i]);
	}
	
	quickSort(arr_y, arr_x, 0, n-1);
	
	for(int i=0;i<n;i++){
		printf("%d %d\n", arr_x[i],arr_y[i]);
	}
	
	return 0;
}