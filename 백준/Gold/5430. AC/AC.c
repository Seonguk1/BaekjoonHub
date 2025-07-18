#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char p[100001];
        int n;
        scanf("%s", p);
        scanf("%d", &n);

        int arr[100001];
        int front = 0, rear = n - 1;
        int reversed = 0, error = 0;

        char s[400001];
        scanf("%s", s);

        // 숫자 파싱
        int idx = 0, num = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == ',' || s[i] == ']') {
                if (num > 0 || (i > 0 && s[i-1] == '0'))  // 0 처리 포함
                    arr[idx++] = num;
                num = 0;
            }
        }

        for (int i = 0; p[i]; i++) {
            if (p[i] == 'R') {
                reversed = !reversed;
            } else if (p[i] == 'D') {
                if (front > rear) {
                    error = 1;
                    break;
                }
                if (!reversed) front++;
                else rear--;
            }
        }

        if (error) {
            printf("error\n");
        } else {
            printf("[");
            if (!reversed) {
                for (int i = front; i <= rear; i++) {
                    printf("%d", arr[i]);
                    if (i < rear) printf(",");
                }
            } else {
                for (int i = rear; i >= front; i--) {
                    printf("%d", arr[i]);
                    if (i > front) printf(",");
                }
            }
            printf("]\n");
        }
    }
    return 0;
}
