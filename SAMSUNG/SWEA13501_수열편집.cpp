#include <iostream>

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

void insertNode(int idx, int data) {
    Node *new_node = getNode(data);
    Node *temp = head;
    for (int i = 0; i < idx; i++) temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(int idx) {
    Node *temp = head;
    for (int i = 0; i < idx; i++) temp = temp->next;
    if (temp->next != nullptr)temp->next = temp->next->next;
}

void changeNode(int idx, int data) {
    Node *temp = head;
    for (int i = 0; i <= idx; i++) temp = temp->next;
    temp->data = data;
}

void printNode(int idx) {
    Node *temp = head;
    for (int i = 0; i <= idx; i++) {
        if(temp->next == nullptr) {
            cout << -1 << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << temp->data << "\n";
}

int main() {
    int T, test_case;
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        init();
        int n, m, l, data, x, y;
        char oper;
        cin >> n >> m >> l;
        for (int i = 0; i < n; i++) {
            cin >> data;
            addNodeTail(data);
        }
        for (int i = 0; i < m; i++) {
            cin >> oper;
            if (oper == 'I') {
                cin >> x >> y;
                insertNode(x, y);
            } else if (oper == 'D') {
                cin >> x;
                deleteNode(x);
            } else if (oper == 'C') {
                cin >> x >> y;
                changeNode(x, y);
            }
        }
        cout << '#' << test_case << " ";
        printNode(l);
    }
    return 0;
}