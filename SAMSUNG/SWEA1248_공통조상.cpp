#include <iostream>
#include <cstring>

using namespace std;
int v, e, first, second, ans;
struct Node {
    int par, left, right;
};
int visited[10001];
Node tree[10001];

void dfs(int cur) {
    int left = tree[cur].left;
    int right = tree[cur].right;
    if (visited[cur]) return;
    if (left != 0) dfs(left);
    if (right != 0) dfs(right);
    ans++;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        memset(visited, 0, sizeof(visited));
        ans = 0;
        cin >> v >> e >> first >> second;
        for (int i = 0; i <= v; i++) tree[i].par = 0, tree[i].left = 0, tree[i].right = 0;
        for (int i = 0; i < e; i++) {
            int par, child;
            cin >> par >> child;
            tree[child].par = par;
            if (tree[par].left == 0) tree[par].left = child;
            else tree[par].right = child;
        }
        int cur = first;
        while (true) {
            if (visited[cur]) continue;
            visited[cur] = true;
            if (cur == 1) break;
            cur = tree[cur].par;
        }
        int lca;
        int cur2 = second;
        while (true) {
            if (visited[cur2]) {
                lca = cur2;
                break;
            }
            cur2 = tree[cur2].par;
        }
        memset(visited, 0, sizeof(visited));
        dfs(lca);
        cout << '#' << tc << ' ' << lca << ' ' << ans << '\n';
    }
}