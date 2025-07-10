#include <stdio.h>

int main(){
    int n, i, c=0;
    scanf("%d", &n);
    
    for(i=666;c!=n;i++){
        int temp = i, a=0;
        while(temp != 0){
            if(temp%10 == 6){
                a++;
                if(a==3){
                    c++;
                    break;
                }
            }
            else a=0;
            temp/=10;
        }
    }
    printf("%d", i-1);
}