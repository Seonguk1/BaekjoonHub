#include <stdio.h>
#include <math.h>
int main(){
    int a,b,v;
    scanf("%d %d %d", &a,&b,&v);
    int t = (v-b)/(a-b);
    if((v-b)%(a-b)) t++; 
    printf("%d", t);
}