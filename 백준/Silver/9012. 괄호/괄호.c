#include <stdio.h>

int main() {
    int n;
    char str[51], stack[51];
    scanf("%d", &n);
    while(n--){
        int isVPS = 1, top=-1;
        for(int i=0;str[i];i++){
            str[i] = '\0';
        }
        scanf("%s", str);
        for(int i=0;str[i];i++){
            if(str[i]=='('){
                stack[++top] = '(';
            }
            else{
                if(top==-1){
                    isVPS = 0;
                    break;
                }
                top--;
            }
        }
        if(isVPS && top==-1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}