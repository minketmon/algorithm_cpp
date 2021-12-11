#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[101][101], visited[101][101];
int n, m, cnt;
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0,};
int cheese_cnt = 0;
vector<pair<int, int>> v;
vector<int> cheese_v;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    map[a][b] = cnt + 2;
    visited[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
            if (visited[nx][ny] == false) {
                if (map[nx][ny] == 1) {
                    v.push_back({nx, ny});
                } else if (map[nx][ny] != 1) {
                    visited[nx][ny] = true;
                    map[nx][ny] = 2 + cnt;
                    q.push({nx, ny});
                }

            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    while (true) {
        cheese_cnt = 0;
        memset(visited, 0, sizeof(visited));
        v.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) cheese_cnt++;
            }
        }
        cheese_v.push_back(cheese_cnt);
        if (cheese_cnt == 0) break;
        bfs(0, 0);
        for (auto a: v) map[a.first][a.second] = cnt + 2;
        cnt++;
    }
    cout << cnt << "\n" << cheese_v[cheese_v.size()-2];
}