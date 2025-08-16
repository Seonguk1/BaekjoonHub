#include <stdio.h>

long long a,b;

long long f(long long n){
    if(n==b) return 0;
    if(n > b) return -1;
    long long count = -1;
    long long result = f(n*2);
    if(result != -1 && (count == -1 || result < count)) count = result+1;
    result = f(n*10+1);
    if(result != -1 && (count == -1 || result < count)) count = result+1;
    return count;
}

int main() {
    scanf("%lld %lld",&a,&b);
    printf("%lld", f(a)==-1 ? f(a) : f(a)+1);
    return 0;
}