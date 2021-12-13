#include <iostream>
#include <queue>
#include <vector>

#define INF 123456789
using namespace std;
int n, m, start, dest;
int dist[1001];
vector<pair<int, int>> edge[1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; // 출 도 간
        edge[a].emplace_back(b, c);
    }
    cin >> start >> dest;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int next = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if (dist[next] != INF) continue;
        dist[next] = weight;
        for (int i = 0; i < edge[next].size(); i++) {
            int vertex = edge[next][i].first;
            int total = weight + edge[next][i].second;
            if (dist[vertex] <= total) continue;
            pq.push({-total, vertex});
        }
    }
    cout << dist[dest];
}