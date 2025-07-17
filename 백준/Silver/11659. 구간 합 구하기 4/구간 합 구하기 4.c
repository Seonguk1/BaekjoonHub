#include <stdio.h>

int arr[100001];

int f(int i, int j){
    
}

int main(){
    int n,m, r=0;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[i]);
        r += arr[i];
    }
    while(m--){
        int i,j, sum=0, h=0;
        scanf("%d %d",&i,&j);
        if(j-i+1 < n/2)
            for(int k=0; k<=(j-i)/2; k++){
                if(i+k == j-k) sum+=arr[i+k];
                else sum+= arr[i+k] + arr[j-k];
            }
        else{
            for(int k=1; k<i; k++){
                h += arr[k];
            }
            for(int k=j+1; k<=n; k++){
                h += arr[k];
            }
            sum = r-h;
        }
        printf("%d\n",sum);
    }
}