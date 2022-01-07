#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, g, r, can_cnt, f_cnt, ans;
int init_map[51][51];
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
vector<pair<int, int>> can, green, red;

void bfs(int map[51][51]) {
    f_cnt = 0;
    queue<pair<int, int>> q;
    for (auto a: green) {
        map[a.first][a.second] = 3;
        q.push(a);
    }
    for (auto a: red) {
        map[a.first][a.second] = 4;
        q.push(a);
    }
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        int color = map[cur_x][cur_y];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (map[nx][ny] == 0) continue;
            if (map[nx][ny] == 5) continue;
            if(map[nx][ny])
        }
    }
    ans = f_cnt > ans ? f_cnt : ans;
}

void combination(int cnt, int gg, int rr) {
    if (gg == g && rr == r) {
        int map[51][51];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                map[i][j] = init_map[i][j];
            }
        }
        bfs(map);
        return;
    }
    if (cnt == can_cnt)return;
    if (gg < g) {
        int x = can[cnt].first;
        int y = can[cnt].second;
        green.push_back({x, y});
        combination(cnt + 1, gg + 1, rr);
        green.pop_back();
    }
    if (rr < r) {
        int x = can[cnt].first;
        int y = can[cnt].second;
        red.push_back({x, y});
        combination(cnt + 1, gg, rr + 1);
        red.pop_back();
    }
    combination(cnt + 1, gg, rr);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> g >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> init_map[i][j];
            if (init_map[i][j] == 2) can_cnt++, can.push_back({i, j});
        }
    }
    combination(0, 0, 0);
    cout << ans;
}