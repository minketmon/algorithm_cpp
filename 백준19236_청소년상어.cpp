#include <iostream>
#include <algorithm>

using namespace std;
int ans = 0;
int x[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int y[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
pair<int, int> map[17][17], location[17];

void dfs(pair<int, int> map[17][17], pair<int, int> location[17], int shark_x, int shark_y, int _sum) {
    pair<int, int> m[17][17], l[17];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            m[i][j] = map[i][j];
    }
    for (int i = 1; i <= 16; i++) l[i] = location[i];
    int will_die = m[shark_x][shark_y].first;
    int shark_dir = m[shark_x][shark_y].second;
    m[shark_x][shark_y].second = -1;
    l[will_die] = {-1, -1};
    _sum += will_die;
    ans = max(ans, _sum);
    for (int i = 1; i <= 16; i++) { // 물고기 이동
        int cur_x = l[i].first;
        int cur_y = l[i].second;
        int dir = m[cur_x][cur_y].second;
        if (cur_x == -1 && cur_y == -1) continue;
        int nx = cur_x, ny = cur_y;
        while (true) {
            if (dir == 9) dir = 1;
            nx = cur_x + x[dir];
            ny = cur_y + y[dir];
            if (nx == shark_x && ny == shark_y) {
                dir++;
                continue;
            }
            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) break;
            dir++;
        }
        l[i] = {nx, ny};
        int next_fish = m[nx][ny].first;
        int next_fish_dir = m[nx][ny].second;
        if (next_fish_dir != -1) {
            l[next_fish] = {cur_x, cur_y};
            m[cur_x][cur_y] = {next_fish, next_fish_dir};
            m[nx][ny] = {i, dir};
        } else {
            l[next_fish] = {cur_x, cur_y};
            m[cur_x][cur_y] = {next_fish, -1};
            m[nx][ny] = {i, dir};
        }
    }
    for (int i = 1; i <= 3; i++) { // 상어 이동
        int nx = shark_x + x[shark_dir] * i;
        int ny = shark_y + y[shark_dir] * i;
        if (nx < 0 || ny < 0 || nx > 3 || ny > 3) break;
        if (m[nx][ny].second != -1) {
            dfs(m, l, nx, ny, _sum);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j].first >> map[i][j].second;
            location[map[i][j].first] = {i, j};
        }
    }
    dfs(map, location, 0, 0, 0);
    cout << ans;
}