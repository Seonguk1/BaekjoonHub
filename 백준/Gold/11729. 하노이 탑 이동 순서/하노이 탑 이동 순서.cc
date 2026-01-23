#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int N,K=0;
vector<pair<int,int>> V;
void func(int index, int cur_loc, int tar_loc){
    K++;
    if (index==1) {
        V.push_back({cur_loc, tar_loc});
        return;
    }
    func(index-1, cur_loc, 6-cur_loc-tar_loc);
    V.push_back({cur_loc, tar_loc});
    func(index-1, 6-cur_loc-tar_loc, tar_loc);
}

int main(){
    cin >> N;
    func(N, 1, 3);
    cout << K << "\n";
    for (auto v : V) {
        cout << v.first << " " << v.second << "\n";
    }
    return 0;
}