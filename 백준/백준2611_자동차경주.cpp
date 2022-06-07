#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, in[1001], dist[1001], route[1001];
bool visited[1001];
vector<pair<int, int>> v[1001], v2[1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v2[y].push_back({x, z});
        in[y]++;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto a: v[cur]) {
            int next = a.first;
            int weight = a.second;
            if (in[next] > 0) {
                in[next]--;
                route[next] = cur;
                if (dist[next] < dist[cur] + weight)
                    dist[next] = dist[cur] + weight;
            }
            if (in[next] == 0) q.push(next);
        }
    }
    vector<int> res;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto a: v2[cur]) {
            int next = a.first;
            int weight = a.second;
            if (dist[cur] - weight == dist[next]) {
                q.push(next);
            }
        }
    }
    res.push_back(1);
    cout << dist[1] << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
}