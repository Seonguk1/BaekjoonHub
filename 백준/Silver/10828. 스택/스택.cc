#include<iostream>
using namespace std;
// 스택 만드는 방법
// 1. 배열 -> 구현이 간단
// 2. 연결리스트 -> 중간 삽입 삭제가 쉽다

int stack[10001];
int top = -1;

void push(int m){
    stack[++top] = m;
}

int pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >>str;
        if(str == "push"){
            int m;
            cin >> m;
            push(m);
        }
        else if(str == "pop"){
            cout << pop() << endl;
        }
        else if(str == "size"){
            cout << top+1 << endl;
        }
        else if(str == "empty"){
            cout << (top == -1 ? 1 : 0) << endl;
        }
        else{
            cout << (top != -1 ? stack[top] : -1) << endl; 
        }
    }   
}