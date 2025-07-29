#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> origin(n);       // 입력 좌표
    vector<int> sorted;          // 중복 제거용 정렬 벡터

    for (int i = 0; i < n; ++i) {
        cin >> origin[i];
        sorted.push_back(origin[i]);
    }

    // 중복 제거 후 정렬
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    // 좌표 → 압축 값 매핑
    map<int, int> compressed;
    for (int i = 0; i < sorted.size(); ++i) {
        compressed[sorted[i]] = i;
    }

    // 원래 입력 순서대로 압축 값 출력
    for (int i = 0; i < n; ++i) {
        cout << compressed[origin[i]] << " ";
    }

    return 0;
}
