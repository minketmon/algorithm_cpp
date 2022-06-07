#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF 123456789
using namespace std;
int n, m, d, e, h[100001];
long long dist[100001], dist2[100001];
long long ans = LLONG_MIN;
vector<pair<int, int>> edge[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> d >> e;
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX, dist2[i] = LLONG_MAX;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }
    dist[1] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int next = pq.top().second;
        long long weight = -pq.top().first;
        pq.pop();
        if (dist[next] < weight) continue;
        for (auto &i: edge[next]) {
            int vertex = i.first;
            long long total = weight + i.second;
            if (h[next] >= h[vertex]) continue;
            if (dist[vertex] <= total) continue;
            dist[vertex] = total;
            pq.push({-total, vertex});
        }
    }
    dist2[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        int next = pq.top().second;
        long long weight = -pq.top().first;
        pq.pop();
        if (dist2[next] < weight) continue;
        for (auto &i: edge[next]) {
            int vertex = i.first;
            long long total = weight + i.second;
            if (h[next] >= h[vertex]) continue;
            if (dist2[vertex] <= total) continue;
            dist2[vertex] = total;
            pq.push({-total, vertex});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX || dist2[i] == LLONG_MAX) continue;
        long long a = (dist[i] + dist2[i]) * d;
        long long b = h[i] * e;
        ans = max(ans, b - a);
    }
    if (ans == LLONG_MIN) cout << "Impossible\n";
    else cout << ans << "\n";
}