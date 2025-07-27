#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
    
    int n,c=1;
    cin >> n;

    vector<string> v;
    v.push_back("ChongChong");
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        auto it1 = find(v.begin(),v.end(),s1);
        auto it2 = find(v.begin(),v.end(),s2);
        if(it1 == v.end() && it2 != v.end()){
            c++;
            v.push_back(s1);
        }
        else if(it2 == v.end() && it1 != v.end()){
            c++;
            v.push_back(s2);
        }
    }
    cout << c;
}