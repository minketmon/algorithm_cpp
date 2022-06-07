#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define MAX_NODE 40001
#define swap(a, b){ int temp = a; a = b; b = temp; }
int depth[MAX_NODE], max_level;
int anc[MAX_NODE][20];
long long dist[MAX_NODE];
vector<pair<int, int>> tree[MAX_NODE];

void getTree(int here, int parent, int weight) {
    depth[here] = depth[parent] + 1;
    anc[here][0] = parent;
    if (here != 1) dist[here] += dist[parent] + weight;
    for (int i = 1; i <= max_level; i++) {
        int temp = anc[here][i - 1];
        anc[here][i] = anc[temp][i - 1];
    }
    int len = tree[here].size();
    for (int i = 0; i < len; i++) {
        int child = tree[here][i].first;
        if (child != parent) getTree(child, here, tree[here][i].second);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    max_level = (int) floor(log2(MAX_NODE));
    for (int i = 1; i < n; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        tree[from].push_back({to, weight});
        tree[to].push_back({from, weight});
    }
    getTree(1, 0, 0);
    cin >> m;
    while (m--) {
        int a, b, _a, _b;
        cin >> a >> b;
        _a = a, _b = b;
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b]) swap(a, b);
            for (int i = max_level; i >= 0; i--) {
                if (depth[a] <= depth[anc[b][i]])
                    b = anc[b][i];
            }
        }
        int lca = a;
        if (a != b) {
            for (int i = max_level; i >= 0; i--) {
                if (anc[a][i] != anc[b][i])
                    a = anc[a][i], b = anc[b][i];
                lca = anc[a][i];
            }
        }
        int ans = dist[_a] + dist[_b] - 2 * dist[lca];
        cout << ans << '\n';
    }
}
