#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin >> n;

    queue<int> q;

    if(n==1){
        cout << 1;
        return 0;
    }
    
    for(int i=1;i<=n;i++)q.push(i);
    while(true){
        q.pop();
        if(q.size()==1){
            cout << q.front();
            return 0;
        }
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    
}