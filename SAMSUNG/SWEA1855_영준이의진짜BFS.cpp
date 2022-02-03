#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define swap(a, b) {int temp = a; a = b; b = temp;}
#define MAX_NODE 100001

int depth[MAX_NODE], max_level, n;
int anc[MAX_NODE][20];
bool visited[MAX_NODE];
vector<int> tree[MAX_NODE], order;

void setAncestor() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        depth[cur] = d;
        q.pop();
        for (int next: tree[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            anc[next][0] = cur;
            q.push({next, d + 1});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= max_level; j++) {
            int temp = anc[i][j - 1];
            anc[i][j] = anc[temp][j - 1];
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        order.push_back(cur);
        q.pop();
        for (auto next: tree[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) swap(a, b);
        for (int i = max_level; i >= 0; i--)
            if (depth[a] <= depth[anc[b][i]]) b = anc[b][i];
    }
    int ret = a;
    if (a != b) {
        for (int i = max_level; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
            ret = anc[a][i];
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int t, tc;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        max_level = (int) floor(log2(MAX_NODE));
        memset(depth, 0, sizeof(depth));
        memset(anc, 0, sizeof(anc));
        memset(visited, 0, sizeof(visited));
        order.clear();
        for (int i = 0; i <= n; i++) tree[i].clear();
        for (int i = 2; i <= n; i++) {
            int par;
            cin >> par;
            tree[par].push_back(i);
        }
        for (int i = 0; i < n; i++) sort(tree[i].begin(), tree[i].end());
        setAncestor();
        memset(visited, 0, sizeof(visited));
        bfs();
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int lca_ret = lca(order[i], order[i + 1]);
            long long up = depth[order[i]] - depth[lca_ret];
            long long down = depth[order[i + 1]] - depth[lca_ret];
            ans += up, ans += down;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}