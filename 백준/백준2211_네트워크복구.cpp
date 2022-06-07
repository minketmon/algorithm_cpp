#include <iostream>
#include <vector>
#include <queue>

#define INF 123456789
using namespace std;

int n, m, ans, dist[1001], route[1001];
vector<pair<int, int>> res, edge[1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    priority_queue<pair<int, int>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int next = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if (dist[next] == INF) continue;
        for (int i = 0; i < edge[next].size(); i++) {
            int vertex = edge[next][i].first;
            int total = weight + edge[next][i].second;
            if (dist[vertex] <= total) continue;
            dist[vertex] = total;
            route[vertex] = next;
            pq.push({-total, vertex});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (route[i] != 0) {
            ans++;
            res.emplace_back(i, route[i]);
        }
    }
    cout << ans << "\n";
    for (auto &a: res) cout << a.first << " " << a.second << "\n";
}