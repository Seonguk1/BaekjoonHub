// 끝나는 시간이 가장 빠른 회의를 찾고
// 시작 시간이 그 시간보다 같거나 크면서 
// 끝나는 시간이 가장 빠른 회의를 찾는다 -> 반복
// 시간 초과..

// 2) 정렬
// end 오름차순 정렬,
// end 같을 경우는 start 오름차순 정렬

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct Meeting{
    int start;
    int end;
} Meeting;

Meeting m[100001];

int compare(const void* a, const void* b){
    Meeting* x = (Meeting*)a;
    Meeting* y = (Meeting*)b;
    if(x->end == y->end)
        return x->start - y->start;
    else
        return x->end - y->end;
}

int main(){
    int n,s,e;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &s,&e);
        m[i].start = s;
        m[i].end = e;
    }

    qsort(m, n, sizeof(Meeting), compare);
    
    int i, end_idx = 0, count=0;
    while(1){
        for(i=end_idx+1;m[i].start < m[end_idx].end && i<n;i++){
        }
        if(i != n){
            end_idx = i;
            count++;
        }
        else{
            printf("%d", count+1);
            return 0;
        }
    }

    // 1) 시간초과
    // int st = 0, count=0;
    // while(1){
    //     int min = pow(2,31)-1, isFind = 0;
    //     for(int i=0;i<n;i++){
    //         if(m[i].start >= st && m[i].end <= min){
    //             isFind = 1;
    //             min = m[i].end;  
    //         } 
    //     }
    //     if(!isFind){
    //         break;
    //     }
    //     count++;
    //     st = min;
    // }
    // printf("%d",count);
}