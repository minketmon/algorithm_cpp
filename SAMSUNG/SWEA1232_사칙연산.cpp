#include <iostream>

using namespace std;
struct Node {
    char op;
    int data, left, right;
};
int n;
Node tree[1001];

int postOrder(int idx) {
    char o = tree[idx].op;
    if (o == '+') return postOrder(tree[idx].left) + postOrder(tree[idx].right);
    else if (o == '-') return postOrder(tree[idx].left) - postOrder(tree[idx].right);
    else if (o == '*') return postOrder(tree[idx].left) * postOrder(tree[idx].right);
    else if (o == '/') return postOrder(tree[idx].left) / postOrder(tree[idx].right);
    else return tree[idx].data;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int idx, left, right;
            string s;
            cin >> idx >> s;
            if (s[0] - '0' >= 0 && s[0] - '0' < 10) {
                int val = s[0] - '0';
                for (int j = 1; j < s.size(); j++)
                    val = s[j] - '0' + (val * 10);
                tree[idx].op = 0, tree[idx].data = val;
                tree[idx].left = 0, tree[idx].right = 0;
            } else {
                cin >> left >> right;
                tree[idx].op = s[0], tree[idx].data = 0;
                tree[idx].left = left, tree[idx].right = right;
            }
        }
        cout << '#' << tc << ' ' << postOrder(1) << '\n';
    }
}