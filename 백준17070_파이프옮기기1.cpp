#include <iostream>
#include <queue>

using namespace std;
int n, cnt, map[20][20];
int x[] = {0, 1, 1};
int y[] = {1, 0, 1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    if (map[n][n] == 1) {
        cout << cnt;
        return 0;
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 2}});
    while (!q.empty()) {
        int state = q.front().first;
        int cur_x = q.front().second.first;
        int cur_y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 3; i++) {
            if (state == 0 && i == 1) continue;
            if (state == 1 && i == 0) continue;
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx > n || ny > n) continue;
            if (nx == n && ny == n) {
                if (i == 2) {
                    if (map[nx][ny - 1] == 1 || map[nx - 1][ny] == 1) continue;
                }
                cnt++;
                continue;
            }
            if (i == 2) {
                if (map[nx][ny - 1] == 1 || map[nx - 1][ny] == 1) continue;
            }
            if (map[nx][ny] == 1) continue;
            if (i == 0 && ny >= n) continue;
            if (i == 1 && nx >= n) continue;
            q.push({i, {nx, ny}});
        }
    }
    cout << cnt;
}