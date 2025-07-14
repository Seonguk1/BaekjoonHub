#include <stdio.h>

int arr[9];

void f(int n, int m, int size){

    for(int i=1;i<=n;i++){
        int c=0;
        arr[size-m] = i;
        if(m==1){
            for(int i=0;arr[i];i++){
                if(i != size-m && arr[i] == arr[size-m]){
                    c = 1;
                    break;
                }
            }
            if(!c){
                for(int i=0;arr[i];i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
        else{
            for(int i=0;i<size-m;i++){
                if(i != size-m && arr[i] == arr[size-m]){
                    c = 1;
                    break;
                }
            }
            if(!c) f(n,m-1,size);
        }
    }
    
}

int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    f(n,m,m);
}