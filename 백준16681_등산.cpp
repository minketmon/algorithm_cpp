#include <iostream>
#include <vector>
#include <queue>

#define INF 123456789
using namespace std;
int n, m, d, e, cur_h, h[100001], dist[100001];
vector<pair<int, int>> edge[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> d >> e;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int next = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if (dist[next]==INF) continue;
        for (auto & i : edge[next]) {
            int vertex = i.first;
            int total = weight + i.second;
            if(dist[vertex] <= total) continue;
            dist[vertex] = total;
            pq.push({-total, vertex});
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
}