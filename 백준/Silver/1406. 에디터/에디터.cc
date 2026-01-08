#include <iostream>
using namespace std;

struct Node{
    struct Node *prev, *next;
    char data;
};

Node *head, *cursor;
string s;
int M;

Node* createNode(char data){
    Node* node = new Node;
    node->prev = NULL; node->next = NULL;
    node->data = data;
    return node;
}

void push_back(char data){
    cursor->next = createNode(data);
    cursor->next->prev = cursor;
    cursor = cursor->next;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> M;
    head = createNode(' ');
    cursor = head;
    for (auto c : s){
        push_back(c);
    }
    
    while(M--){
        char com, c;
        cin >> com;
        Node* prev = cursor->prev;
        Node* next = cursor->next;
        if (com == 'L') {
            if (prev == NULL) continue;
            cursor = prev;
        }
        else if (com == 'D') {
            if (next == NULL) continue;
            cursor = next;
        }
        else if (com == 'B') {
            if (prev == NULL) continue;
            Node* del = cursor;
            prev->next = next;
            if (next != NULL) next->prev = prev;
            cursor = prev;
            delete del;
        }
        else if (com == 'P') {
            cin >> c;
            Node* node = createNode(c);
            node->prev = cursor;
            
            cursor->next = node;
            if (next != NULL) {
                node->next = next;
                next->prev = node;
            }
            
            cursor = cursor->next;
        }
    }

    Node* cur = head->next;
    while(cur != NULL){
        cout << cur->data;
        cur = cur->next;
    }
    return 0;
}