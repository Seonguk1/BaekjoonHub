#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    // 입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    // pq1: 양수 저장 (작은 값이 top - Min Heap)
    priority_queue<int, vector<int>, greater<int>> pq1;
    // pq2: 음수 저장 (큰 값이 top - Max Heap, 그래야 절댓값이 작음)
    priority_queue<int> pq2;

    cin >> N;
    while(N--){
        cin >> x;
        if (x == 0) {
            if (pq1.empty() && pq2.empty()) {
                cout << "0\n";
            }
            else if (pq1.empty()) { // 음수만 있을 때
                cout << pq2.top() << "\n";
                pq2.pop();
            }
            else if (pq2.empty()) { // 양수만 있을 때
                cout << pq1.top() << "\n";
                pq1.pop();
            }
            else {
                // 둘 다 있을 때 비교
                // 절댓값이 같으면 음수(pq2.top)를 출력해야 함
                if (pq1.top() < abs(pq2.top())) {
                    cout << pq1.top() << "\n";
                    pq1.pop();
                } else {
                    cout << pq2.top() << "\n";
                    pq2.pop();
                }
            }
        }
        else {
            if (x > 0) pq1.push(x);
            else pq2.push(x);
        }
    }
    return 0;
}