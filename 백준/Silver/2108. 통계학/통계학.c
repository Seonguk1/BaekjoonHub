#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(const void* a, const void*b){
    return *(const int*)a - *(const int*)b;
}

int main(){
    int n,m, max=-4000, min = 4000, count[8001]={0,}, arr[500001];
    double sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d", &m);
        arr[i] = m;
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
        count[4000+arr[i]]++;
    }

    int count_max = 0, idx = 0;
    for(int i=0;i<8001;i++){
        if(count[i] > count_max){
            count_max = count[i];
            idx = i-4000;
        } 
    }

    int c = 0, k;
    for(int i=0;i<8001;i++){
        if(count[i] == count_max){
            if(c == 0) c=1;
            else{
                k = i-4000;
                c=0;
                break;
            }
        }
    }
    if(c==1) k = idx;
    
    qsort(arr, n, sizeof(int), compare);
    int avg = round(sum/n);
    if(avg == -0) avg = 0;
    printf("%d\n%d\n%d\n%d", avg, arr[n/2],k,max-min);
}