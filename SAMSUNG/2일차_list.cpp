#include <iostream>

using namespace std;

struct Node {
    int idx;
    Node *link;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    Node *delete_node;
    Node *first = (Node *) malloc(sizeof(Node));
    Node *node = first;
    node->idx = 1;
    for (int i = 2; i <= n; i++) {
        node->link = (Node *) malloc(sizeof(Node));
        node = node->link;
        node->idx = i;
    }
    node->link = first;
    node = node->link;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <k; j++) {
            node = node->link;
        }
        delete_node = node->link;
        node->link = delete_node->link;
        free(delete_node);
        node = node->link;
    }
    cout << node->idx << "\n";
}