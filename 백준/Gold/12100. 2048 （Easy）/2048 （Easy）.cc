#include <iostream>
using namespace std;
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

int N, max_num=0, c=0;
int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};

void move_line(int* board, int start_x, int start_y, int dir){
    int x = start_x, y = start_y;
    for (int i=0; i<N-1; i++) {
        if(board[y*N + x]==0){
            board[y*N + x] = board[(y+dy[dir])*N + x+dx[dir]];
            board[(y+dy[dir])*N + x+dx[dir]] = 0;
        }
        x += dx[dir];
        y += dy[dir];
    }
}

void move_board(int* board, int dir){
    for (int i=0; i<N; i++) {
        int start_x;
        int start_y;
        if (dir==DOWN) {
            start_x = i; start_y = N-1;
        } 
        else if (dir == UP) {
            start_x = i; start_y = 0;
        }
        else if (dir == RIGHT) {
            start_x = N-1; start_y = i;
        }
        else{
            start_x = 0; start_y = i;
        }
        
        // move
        for (int j=0; j<N-1; j++) {
            move_line(board, start_x, start_y, dir);
        }

        // 합치기
        int x = start_x;
        int y = start_y;
        for (int j=0; j<N; j++) {
            if (x<0 || y< 0 || x>=N || y>=N) continue;
            if(y+dy[dir] < 0 || x+dx[dir] < 0 || y+dy[dir] >= N || x+dx[dir] >= N) continue;
            if (board[y*N + x] == board[(y+dy[dir])*N + x+dx[dir]]) {
                board[y*N + x] *= 2;
                board[(y+dy[dir])*N + x+dx[dir]] = 0;
                move_line(board, start_x, start_y, dir);
            }
            x += dx[dir];
            y += dy[dir];
        }
    }
}

void play(int* board, int depth){
    // cout << c << endl;
    //     for (int i=0; i<N; i++) {
    //         for (int j=0; j<N; j++) {
    //             cout << board[i*N + j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    //     c++;
    if (depth == 5) {
        int max_temp = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if(board[i*N+j] > max_temp){
                    max_temp = board[i*N+j];
                }
            }
        }
        if (max_temp > max_num) {
            max_num = max_temp;
        }
        return;
    }
    
    for (int i=0; i<4; i++) {
        int* temp = new int[N*N];
        for (int j=0; j<N*N; j++) {
            temp[j] = board[j];
        }
        move_board(temp, i);
        play(temp, depth+1);
        delete[] temp;
    }
}

int main() {
    cin >> N;
    int board[N*N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i*N + j];
        }
    }
    
    play(board, 0);    
    
    cout << max_num;

    // for (int i=0; i<N; i++) {
    //     for (int j=0; j<N; j++) {
    //         cout << board[i*N + j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}