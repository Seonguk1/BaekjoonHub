#include <stdio.h>
#include <stdbool.h> // bool 타입 사용
#include <string.h>  // memset 사용

#define MAX_SIZE 51 // N, M의 최대값 50 + 1 (0-based indexing 기준)

int M, N, K; // M: 가로길이(열), N: 세로길이(행), K: 배추 개수
int field[MAX_SIZE][MAX_SIZE]; // 밭 상태 (1: 배추, 0: 없음)
bool visited[MAX_SIZE][MAX_SIZE]; // 방문 여부 기록

// 상하좌우 이동을 위한 배열
int dr[] = {-1, 1, 0, 0}; // 상, 하
int dc[] = {0, 0, -1, 1}; // 좌, 우

// DFS 함수: (r, c)에서 시작하여 연결된 모든 배추를 탐색
void dfs(int r, int c) {
    visited[r][c] = true; // 현재 위치 방문 처리

    // 상하좌우 네 방향으로 이동
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i]; // 다음 행
        int nc = c + dc[i]; // 다음 열

        // 1. 밭의 경계 내에 있는지 확인
        if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
            // 2. 다음 위치에 배추가 있고 (field[nr][nc] == 1)
            // 3. 아직 방문하지 않았다면 (!visited[nr][nc])
            if (field[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc); // 재귀적으로 DFS 호출
            }
        }
    }
}

int main() {

    int T; // 테스트 케이스 개수
    scanf("%d", &T);

    while (T--) { // 각 테스트 케이스 처리
        scanf("%d %d %d", &M, &N, &K); // M, N, K 입력

        // 밭과 방문 배열 초기화
        memset(field, 0, sizeof(field));     // 모든 밭을 0으로 초기화 (배추 없음)
        memset(visited, false, sizeof(visited)); // 모든 방문 기록을 false로 초기화

        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int c, r; // 문제에서 (가로, 세로)로 주어지므로, c가 M(열), r이 N(행)에 해당
            scanf("%d %d", &c, &r);
            field[r][c] = 1; // 밭에 배추 표시
        }

        int worm_count = 0; // 필요한 지렁이 마릿수 (배추 덩어리 개수)

        // 밭 전체를 순회하며 배추 덩어리 탐색
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                // 현재 위치에 배추가 있고 아직 방문하지 않았다면
                if (field[r][c] == 1 && !visited[r][c]) {
                    dfs(r, c); // 새로운 배추 덩어리 발견! DFS 시작하여 연결된 모든 배추 방문
                    worm_count++; // 지렁이 마릿수 1 증가
                }
            }
        }
        printf("%d\n", worm_count); // 결과 출력
    }

    return 0;
}