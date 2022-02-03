#include <iostream>

using namespace std;
int n, tree[201][2], idx;
bool isNumber[201];
char tree_data[201], order[202];

void inOrder(int root) {
    if (root < 1) return;
    inOrder(tree[root][0]);
    order[idx++] = tree_data[root];
    inOrder(tree[root][1]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++) {
        idx = 0;
        memset(tree, 0, sizeof(tree));
        memset(isNumber, 0, sizeof(isNumber));
        memset(tree_data, 0, sizeof(tree_data));
        memset(order, 0, sizeof(order));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int num, left, right;
            char op;
            cin >> num >> op;
            tree_data[num] = op;
            if (num <= n / 2) {
                if (num == n / 2 && n % 2 == 0) {
                    cin >> left;
                    tree[num][0] = left;
                } else {
                    cin >> left >> right;
                    tree[num][0] = left;
                    tree[num][1] = right;
                }
            }
        }
        inOrder(1);
        for (int i = 0; i < n; i++)
            if (order[i] - '0' >= 0 && order[i] - '0' < 10) isNumber[i] = true;
        bool ans = true;
        for (int i = 0; i < n - 1; i++)
            if (isNumber[i] == isNumber[i + 1]) ans = false;
        cout << '#' << tc << ' ' << ans << '\n';
    }
}