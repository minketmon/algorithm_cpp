#include <iostream>
#include <cstring>

using namespace std;
int tree[101][3];
char alpha[101];

void inorder(int root) {
    if (root < 1) return;
    inorder(tree[root][0]);
    cout << alpha[root];
    inorder(tree[root][1]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++) {
        cout << '#' << tc << " ";
        memset(tree, 0, sizeof(tree));
        memset(alpha, 0, sizeof(alpha));
        int n, par, left, right;
        char c;
        cin >> n;
        for (int i = 0; i < n; i++) {
            left = -1, right = -1;
            cin >> par >> c;
            if (cin.get() != '\n') {
                cin >> left;
                if (cin.get() != '\n') cin >> right;
            }
            tree[par][0] = left;
            tree[par][1] = right;
            alpha[par] = c;
        }
        inorder(1);
        cout << "\n";
    }
}