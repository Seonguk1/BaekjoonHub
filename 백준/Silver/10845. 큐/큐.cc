#include <iostream>
using namespace std;

int q[100001];
int front=0,rear=0;

int main() {
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            int m;
            cin >> m;
            q[rear++] = m;
        }
        else if(s=="pop"){
            cout << (front == rear ? -1 : q[front++]) << endl;
        }
        else if(s=="size"){
            cout << rear - front << endl;
        }
        else if(s=="empty"){
            cout << (front == rear ? 1 : 0) << endl;
        }
        else if(s=="front"){
            cout << (front == rear ? -1 : q[front]) << endl;
        }
        else if(s=="back"){
            cout << (front == rear ? -1 : q[rear-1]) << endl;
        }
    }

    return 0;
}