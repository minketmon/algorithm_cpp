#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int k, v, e;
int temp[20001];
bool visited[20001];
vector<int> vec[20001];
int ans = 0;

void dfs(int a) {
    if (visited[a] == false) temp[a] = 1;
    visited[a] = true;
    for (int i = 0; i < vec[a].size(); i++) {
        int next = vec[a][i];
        if (temp[next] == temp[a]) ans = -1;
        if (visited[next] == true) continue;
        if (temp[a] == 1) temp[next] = 2;
        else if (temp[a] == 2) temp[next] = 1;
        visited[next] = true;
        dfs(next);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> v >> e;
        ans = 0;
        memset(visited, 0, sizeof(visited));
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < e; j++) {
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for (int t = 1; t <= v; t++) {
            if (!visited[t])dfs(t);
        }
        for (int j = 0; j <= v; j++) {
            vec[j].clear();
        }
        if (ans == -1) cout << "NO\n";
        else cout << "YES\n";
    }
}