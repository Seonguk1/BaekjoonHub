#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, k, c=0;
    cin >> n >> k;

    queue<int> q;
    
    for(int i=1;i<=n;i++)q.push(i);

    cout <<"<";
    while(true){
        c++;
        if(q.size()==0){
            cout << ">";
            return 0;
        }
            
        if(c%k==0){
            cout << q.front();
            if(q.size() != 1) cout << ", ";
            q.pop();
        }
        else{
            int temp = q.front();
            q.pop();
            q.push(temp);   
        }
    }
    
}