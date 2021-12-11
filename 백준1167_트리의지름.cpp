#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, end_vertex, max_dist, visited[100001];
vector<pair<int, int>> v[100001];

void dfs(int a, int dist) {
    visited[a] = true;
    for (int i = 0; i < v[a].size(); i++) {
        int b = v[a][i].first;
        int w = v[a][i].second;
        if (dist > max_dist) {
            max_dist = dist;
            end_vertex = a;
        }
        if (visited[b]) continue;
        visited[b] = true;
        dfs(b, dist + w);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, w;
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> w;
            v[a].push_back({b, w});
        }
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(end_vertex, 0);
    cout << max_dist;
}