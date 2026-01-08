#include <iostream>
#include <vector>
using namespace std;

void observe(int* arr, int depth);

struct Point {
    int x,y;
};

vector<Point> cctv;

int N,M,min_num=100;

int dx1[4] = {0,1,0,-1};
int dy1[4] = {1,0,-1,0};
int dx2[2][2] = {{1,-1},{0,0}};
int dy2[2][2] = {{0,0},{1,-1}};
int dx3[4][2] = {{1,0}, {1,0}, {-1, 0}, {-1,0}};
int dy3[4][2] = {{0,1}, {0,-1}, {0, 1}, {0,-1}};
int dx4[4][3] = {{1,0,-1}, {1,0,0}, {1,0,-1}, {-1,0,0}};
int dy4[4][3] = {{0,1,0}, {0,1,-1}, {0,-1,0}, {0,1,-1}};
int dx5[4] = {0,1,0,-1};
int dy5[4] = {1,0,-1,0};

void dir1(int* arr, Point p, int depth){
    for (int i=0; i<4; i++) {
        int* temp = new int[N*M];
        for(int i=0;i<N*M;i++) temp[i] = arr[i];
        
        int x = p.x;
        int y = p.y;
        while(true){
            x += dx1[i];
            y += dy1[i];
            if (x<0 || y<0 || x>=M || y>=N) break;
            int& neighbor = temp[y*M + x];
            if (neighbor == 6) break;
            if (neighbor == 0) neighbor = -1;
        }
        observe(temp, depth+1);
        delete[] temp;
    }
}

void dir2(int* arr, Point p, int depth){
    for (int i=0; i<2; i++) {
        int* temp = new int[N*M];
        for(int i=0;i<N*M;i++) temp[i] = arr[i];

        for (int j=0; j<2; j++) {
            int x = p.x;
            int y = p.y;
            while(true){
                x += dx2[i][j];
                y += dy2[i][j];
                if (x<0 || y<0 || x>=M || y>=N) break;
                int& neighbor = temp[y*M + x];
                if (neighbor == 6) break;
                if (neighbor == 0) neighbor = -1;
            }
        }
        observe(temp, depth+1);
        delete[] temp;
    }
}

void dir3(int* arr, Point p, int depth){
    for (int i=0; i<4; i++) {
        int* temp = new int[N*M];
        for(int i=0;i<N*M;i++) temp[i] = arr[i];

        for (int j=0; j<2; j++) {
            int x = p.x;
            int y = p.y;
            while(true){
                x += dx3[i][j];
                y += dy3[i][j];
                if (x<0 || y<0 || x>=M || y>=N) break;
                int& neighbor = temp[y*M + x];
                if (neighbor == 6) break;
                if (neighbor == 0) neighbor = -1;
            }
        }
        observe(temp, depth+1);
        delete[] temp;
    }
}

void dir4(int* arr, Point p, int depth){
    for (int i=0; i<4; i++) {
        int* temp = new int[N*M];
        for(int i=0;i<N*M;i++) temp[i] = arr[i];

        for (int j=0; j<3; j++) {
            int x = p.x;
            int y = p.y;
            while(true){
                x += dx4[i][j];
                y += dy4[i][j];
                if (x<0 || y<0 || x>=M || y>=N) break;
                int& neighbor = temp[y*M + x];
                if (neighbor == 6) break;
                if (neighbor == 0) neighbor = -1;
            }
        }
        observe(temp, depth+1);
        delete[] temp;
    }
}

void dir5(int* arr, Point p, int depth){
    int* temp = new int[N*M];
    for(int i=0;i<N*M;i++) temp[i] = arr[i];

    for (int j=0; j<4; j++) {
        int x = p.x;
        int y = p.y;
        while(true){
            x += dx5[j];
            y += dy5[j];
            if (x<0 || y<0 || x>=M || y>=N) break;
            int& neighbor = temp[y*M + x];
            if (neighbor == 6) break;
            if (neighbor == 0) neighbor = -1;
        }
    }
    observe(temp, depth+1);
    delete[] temp;
}

void observe(int* arr, int depth){
    if(depth == cctv.size()){
        int count = 0;
        for(int i=0;i<N*M;i++) if(arr[i]==0) count++;
        if(count < min_num) min_num = count;
        return;
    }

    Point p = cctv[depth];
    switch (arr[p.y*M + p.x]) {
        case 1: dir1(arr,p,depth); break;
        case 2: dir2(arr,p,depth); break;
        case 3: dir3(arr,p,depth); break;
        case 4: dir4(arr,p,depth); break;
        case 5: dir5(arr,p,depth); break;
    }
}

int main(){
    cin >> N >> M;
    int arr[N*M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i*M + j];
            if (arr[i*M + j] != 0 && arr[i*M + j] != 6) {
                cctv.push_back({j,i});
            }
        }
    }

    observe(arr,0);

    cout << min_num;
}
