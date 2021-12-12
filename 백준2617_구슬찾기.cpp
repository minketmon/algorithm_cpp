#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, cnt;
bool visited[100];
vector<int> heavier[100], lighter[100], c;

void dfs(int a, vector<int> v[]) {
    visited[a] = true;
    for (int i = 0; i < v[a].size(); i++) {
        if (visited[v[a][i]]) continue;
        visited[v[a][i]] = true;
        cnt++;
        dfs(v[a][i], v);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        heavier[a].push_back(b);
        lighter[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (lighter[i].size() > 0) {
            cnt = 0;
            dfs(i, lighter);
            memset(visited, 0, sizeof(visited));
            if (cnt >= (n + 1) / 2) c.push_back(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (heavier[i].size() > 0) {
            cnt = 0;
            dfs(i, heavier);
            memset(visited, 0, sizeof(visited));
            if (cnt >= (n + 1) / 2) c.push_back(i);
        }
    }
    cout << c.size();
}