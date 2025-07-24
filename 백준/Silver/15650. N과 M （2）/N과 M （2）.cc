#include <iostream>
using namespace std;
int n,m;
int stack[9];
int top = -1;
void f(int a){
    if(top == m-1){ // 가득 찼을 때
        for(int i=0;i<m;i++){
            cout << stack[i] << " ";
        }
        cout << endl;
        top--;
        return ;
    }
    
    for(int i=a;i<=n;i++){
        stack[++top] = i;
        f(i+1);
    }
    top--;
}
int main() {
    cin >> n>>m;
    f(1);
    
    return 0;
}