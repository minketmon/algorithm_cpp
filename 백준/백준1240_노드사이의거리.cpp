#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> v[1001];
bool visited[1001];
int weight[1001][1001];

void bfs(int a, int b) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({a, 0});
    while(!q.empty()) {
        int temp = q.front().first;
        int total_weight = q.front().second;
        q.pop();
        if(temp == b) {
            cout << total_weight << "\n";
            break;
        }
        for(int i=0; i<v[temp].size(); i++) {
            int next = v[temp][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push({next, total_weight + weight[temp][next]});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        weight[a][b] = c;
        weight[b][a] = c;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
}