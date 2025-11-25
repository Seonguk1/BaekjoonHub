#include <stdio.h>

#define MAX 100001
#define INF 1000000000

int dist[MAX];
int dq[200000];   
int head, tail; 
int N, K;

void push_front(int x) {
    head = (head - 1 + 200000) % 200000;
    dq[head] = x;
}

void push_back(int x) {
    dq[tail] = x;
    tail = (tail + 1) % 200000;
}

int pop_front() {
    int x = dq[head];
    head = (head + 1) % 200000;
    return x;
}

int empty() {
    return head == tail;
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < MAX; i++) dist[i] = INF;

    head = tail = 100000;

    dist[N] = 0;
    push_back(N);

    while (!empty()) {
        int x = pop_front();

        if (x == K) break;

        if (x * 2 < MAX && dist[x*2] > dist[x]) {
            dist[x*2] = dist[x];
            push_front(x*2); 
        }

        if (x + 1 < MAX && dist[x+1] > dist[x] + 1) {
            dist[x+1] = dist[x] + 1;
            push_back(x+1);  
        }

        if (x - 1 >= 0 && dist[x-1] > dist[x] + 1) {
            dist[x-1] = dist[x] + 1;
            push_back(x-1);
        }
    }

    printf("%d\n", dist[K]);
    return 0;
}
