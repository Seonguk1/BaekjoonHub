#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[1000001], max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    long long left = 0, right = max, answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)
                sum += arr[i] - mid;
        }

        if (sum >= m) {
            answer = mid;       // 조건을 만족했으므로 저장
            left = mid + 1;     // 더 높게 자를 수 있는지 시도
        } else {
            right = mid - 1;    // 너무 많이 잘라서 부족함 → 낮춰야 함
        }
    }

    printf("%lld", answer);
    return 0;
}
