#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
int n, pcnt[301][301], ans;
bool visited[301][301];
int x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y[] = {0, 1, 1, 1, 0, -1, -1, -1};
char map[301][301];
vector<pair<int, int>> v;

void counting() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '.') {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (map[nx][ny] == '*') cnt++;
                }
                pcnt[i][j] = cnt;
            } else pcnt[i][j] = -1;
        }
    }
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    int v = 0;
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == '*') continue;
            v++;
            visited[nx][ny] = true;
            if (pcnt[nx][ny] == 0) q.push({nx, ny});
        }
    }
    if (v == 0) ans--;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(pcnt, 0, sizeof(pcnt));
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];
        counting();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pcnt[i][j] == 0 && map[i][j] != '*') {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != '*' && pcnt[i][j] > 0 && !visited[i][j]) ans++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}