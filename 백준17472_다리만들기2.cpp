#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, init_map[11][11], map[11][11], num, par[7], ans;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
bool visited[11][11], ivisited[7][7], vis[7];
vector<int> connect[7];
vector<pair<int, pair<int, int>>> v;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    map[a][b] = num;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
            if (visited[nx][ny]) continue;
            if (init_map[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            map[nx][ny] = num;
            q.push({nx, ny});
        }
    }
}

void getDistance(int cur, int a, int b) {
    for (int i = 0; i < 4; i++) {
        int cur_x = a;
        int cur_y = b;
        int d = 0;
        while (true) {
            cur_x += x[i];
            cur_y += y[i];
            if (cur_x < 0 || cur_y < 0 || cur_x > n - 1 || cur_y > m - 1) break;
            if (map[cur_x][cur_y] == cur) break;
            if (map[cur_x][cur_y] != 0) {
                if(ivisited[map[cur_x][cur_y]][cur]) break;
                v.push_back({d, {cur, map[cur_x][cur_y]}});
                ivisited[cur][map[cur_x][cur_y]] = true;
                break;
            }
            d++;
        }
    }
}

int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= 6; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> init_map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (init_map[i][j] == 0) continue;
            if (!visited[i][j]) {
                num++;
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;
            getDistance(map[i][j], i, j);
        }
    }
    sort(v.begin(), v.end());
    for (auto & i : v) {
        int d = i.first;
        int start = i.second.first;
        int dest = i.second.second;
        if (d < 2) continue;
        int x = Find(start);
        int y = Find(dest);
        if (x != y) {
            par[y] = x;
            ans += d;
            connect[start].push_back(dest);
            connect[dest].push_back(start);
        }
    }
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next: connect[cur]){
            if(vis[next]) continue;
            vis[next] = true;
            q.push(next);
        }
    }
    for (int i = 1; i <= num; i++) {
        if(!vis[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << ans << "\n\n";
}