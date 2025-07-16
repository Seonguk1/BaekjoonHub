#include <stdio.h>

int stack[1001];
int top = -1;

void push(int m){
    stack[++top]=m;
}

int pop(){
    if(top==-1) return -1;
    return stack[top--];
}
int main(){
    int n,m,k=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        if(m==k){
            k++;
            while(stack[top]==k){
                pop();
                k++;
            }
        }
        else{
            push(m);
        }
    }
    if(top==-1) printf("Nice");
    else printf("Sad");
}