#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> edge[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < edge[v].size(); i++) {
        int next = edge[v][i];
        if (visited[next] == true) continue;
        dfs(next);
    }
}

void bfs(int v) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int next: edge[now]) {
            if (visited[next] == true) continue;
            q.push(next);
            visited[next] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        sort(edge[i].begin(), edge[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
}