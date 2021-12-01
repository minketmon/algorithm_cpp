#include <iostream>
using namespace std;
int tree[26][2];

void preOrder(int root) {
    if(root < 0) return;
    cout << (char) (root + 'A');
    preOrder(tree[root][0]);
    preOrder(tree[root][1]);
}

void inOrder(int root) {
    if(root < 0) return;
    inOrder(tree[root][0]);
    cout << (char) (root + 'A');
    inOrder(tree[root][1]);
}

void postOrder(int root) {
    if(root < 0) return;
    postOrder(tree[root][0]);
    postOrder(tree[root][1]);
    cout << (char) (root + 'A');
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        if(left != '.') tree[root-'A'][0] = left-'A';
        else tree[root-'A'][0] = -1;
        if(right != '.') tree[root-'A'][1] = right-'A';
        else tree[root-'A'][1] = -1;
    }
    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";
}