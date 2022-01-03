#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, start, dest, ans, cnt, dist[10001], visited[10001], in[10001];
vector<pair<int, int>> v[10001], v2[10001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int s, e, t;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        v[s].push_back({e, t});
        v2[e].push_back({s, t});
        in[e]++;
    }
    cin >> start >> dest;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto &i: v[cur]) {
            int next = i.first;
            if (in[next] > 0) {
                in[next]--;
                if (dist[next] < i.second + dist[cur]) {
                    dist[next] = i.second + dist[cur];
                }
            }
            if (in[next] == 0)
                pq.push({i.second + dist[cur], next});
        }
    }
    ans = dist[dest];
    pq.push({0, dest});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto &i: v2[cur]) {
            int next = i.first;
            int total = i.second;
            if (dist[next] + total == dist[cur]) {
                cnt++;
                if (visited[next]) continue;
                visited[next] = true;
                pq.push({total, next});
            }
        }
    }
    cout << ans << "\n" << cnt;
}