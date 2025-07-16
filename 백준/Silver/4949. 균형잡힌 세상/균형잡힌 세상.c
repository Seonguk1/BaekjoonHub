#include <stdio.h>
#include <string.h>

char stack[201];
int top = -1;

void push(char c){
    stack[++top] = c;
}

int pop(char c){
    if(top==-1) return 0;
    
    if(stack[top] == '(' && c == ')' || stack[top] == '[' && c == ']'){
        top--;
        return 1;
    }
    else
        return 0;
}

int main(){
    char str[102];
    while (1) {
        for(int i=0;i<201;i++){
            stack[i]='\0';
        }
        top=-1;
        
        // "abc." 를 입력하면 "abc.\n\0"로 입력 받음
        // 문자열 최대 길이 : max+2로 해야함
        fgets(str, sizeof(str), stdin);
        
        if(strcmp(str, ".\n")==0) break;
        int a = 0;
        for(int i=0;i<strlen(str);i++){
            if(str[i] == '(' || str[i] == '[') push(str[i]);
            else if(str[i] == ')' || str[i] == ']'){
                if(!pop(str[i])){
                    a=1;
                    break;
                }
            } 
        }
        if(a || top != -1) printf("no\n");
        else printf("yes\n");
    }
}