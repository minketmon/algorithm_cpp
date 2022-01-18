#include <iostream>
#include <cstdio>

#define MAX_NODE 10000
using namespace std;
struct Node {
    int data;
    Node *next;
};

int node_cnt = 0;
Node node[MAX_NODE];
Node *head;

Node *getNode(int data) {
    node[node_cnt].data = data;
    node[node_cnt].next = nullptr;
    return &node[node_cnt++];
}

void init() {
    node_cnt = 0;
    head = getNode(-1);
}

void addNodeTail(int data) {
    Node *new_node = getNode(data);
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
    new_node->next = nullptr;
}

void addNodeIdx(int data, int idx) {
    Node *new_node = getNode(data);
    Node *temp = head;
    for (int i = 0; i < idx; i++) temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(int idx) {
    Node *temp = head;
    for (int i = 0; i < idx; i++) temp = temp->next;
    temp->next = temp->next->next;
}

int main() {
    int test_case;
    for (test_case = 1; test_case <= 10; test_case++) {
        int n, data, x, y, s;
        char oper;
        cin >> n;
        init();
        for (int i = 0; i < n; i++) {
            cin >> data;
            addNodeTail(data);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> oper;
            if (oper == 'I') {
                cin >> x >> y;
                for (int j = 0; j < y; j++) {
                    cin >> s;
                    addNodeIdx(s, x); // x 다음에 s 넣기
                    x++;
                }
            } else if (oper == 'D') {
                cin >> x >> y;
                for (int j = 0; j < y; j++) deleteNode(x);
            } else if (oper == 'A') {
                cin >> y;
                for (int j = 0; j < y; j++) {
                    cin >> s;
                    addNodeTail(s);
                }
            }
        }
        Node *temp = head->next;
        cout << '#' << test_case << " ";
        for (int i = 0; i < 10; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    return 0;
}