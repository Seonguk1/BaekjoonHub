#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void* a, const void* b){
	a = (const char*)a;
	b = (const char*)b;
	if(strlen(a) == strlen(b)){
		return strcmp(a,b);
	}else{
		return strlen(a) - strlen(b);
	}
}

int main(){
	int n;
	
	scanf("%d", &n);
	char arr[n][51];
	for(int i=0;i<n;i++){
		scanf("%s", arr[i]);
	}
	
	qsort(arr, n, 51, compare);
	
	for(int i=0;i<n;i++){
	// set 사용 대신 정렬된 상태에서 전 값과 비교하여 중복 제거
        if(strcmp(arr[i],arr[i-1]) == 0) continue;
		printf("%s\n", arr[i]);
	}
	
	return 0;
}
