#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct User {
    string name;
    int age;
} User;


bool compare(const User &a, const User &b) {
    return a.age < b.age;
}

int main() {
    int n,a;
    cin >> n;
    vector<User>user(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> a >> s;
        user[i].name = s;
        user[i].age = a;
    }
    stable_sort(user.begin(),user.end(),compare);
    for(int i=0;i<n;i++){
        cout << user[i].age << " " << user[i].name << endl;
    }

    return 0;
}