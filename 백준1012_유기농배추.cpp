#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int t, m, n, k, arr[51][51], ans;
int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, -1, 1};
bool visited[51][51];

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + _x[i];
            int ny = cur_y + _y[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (arr[nx][ny] == 1) q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        ans = 0;
        cin >> m >> n >> k;
        vector<pair<int, int>> on;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
            on.push_back({x, y});
        }
        for (auto a: on) {
            if (visited[a.first][a.second]) continue;
            bfs(a.first, a.second);
            ans++;
        }
        cout << ans << '\n';
    }
}