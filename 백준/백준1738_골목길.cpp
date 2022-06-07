#include <iostream>
#include <vector>
#define INF 123456789

using namespace std;
int n, m, dist[101], route[101];
vector<int> res;
vector<pair<pair<int, int>, int>> edge;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({{u, v}, -w});
    }
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (auto &j: edge) {
            int u = j.first.first;
            int v = j.first.second;
            int w = j.second;
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                route[v] = u;
            }
        }
    }
    for (auto &j: edge) {
        int u = j.first.first;
        int v = j.first.second;
        int w = j.second;
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w) { // 사이클 존재
            dist[v] = dist[u] + w;
            route[v] = u;
            for (auto &i: edge) { // 사이클에서 n으로 가는 길 있으면 -1
                if (i.first.first == u && i.first.second == n) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    int idx = n;
    res.push_back(idx);
    while (true) {
        idx = route[idx];
        res.push_back(idx);
        if (idx == 1) break;
    }
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}
