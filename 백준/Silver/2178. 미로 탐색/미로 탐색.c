#include <stdio.h>

#define MAX 101

int n, m;
char map[MAX][MAX];       // 입력받은 미로
int visited[MAX][MAX];    // 방문 여부 및 거리 저장
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct {
    int x, y;
} Queue;

Queue queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Queue dequeue() {
    return queue[front++];
}

int bfs() {
    enqueue(0, 0);
    visited[0][0] = 1; // 시작점은 거리 1

    while (front < rear) {
        Queue p = dequeue();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            // 범위 벗어남
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            // 벽이거나 이미 방문
            if (map[nx][ny] == '0' || visited[nx][ny]) continue;

            visited[nx][ny] = visited[p.x][p.y] + 1;
            enqueue(nx, ny);
        }
    }

    return visited[n-1][m-1];
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    int answer = bfs();
    printf("%d", answer);

    return 0;
}
