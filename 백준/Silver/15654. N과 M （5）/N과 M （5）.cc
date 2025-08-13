#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[9], arr2[9];
bool visited[9];

void chaerin(int d){
    if(d == m){
        for(int i=0;i<m;i++){
            cout << arr2[i]<< " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            arr2[d] = arr[i];
            chaerin(d+1);
            visited[i]=false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    chaerin(0);
    return 0;
}