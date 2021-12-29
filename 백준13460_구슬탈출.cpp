#include <iostream>

using namespace std;

int n, m, ans = 123456789;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
char map[11][11];
pair<int, int> red, blue;

int who_first(int dir, int rx, int ry, int bx, int by) {
    if (dir == 0) {  // 상
        if (rx < bx) return 1;
        else return 0;
    } else if (dir == 1) { // 하
        if (rx > bx) return 1;
        else return 0;
    } else if (dir == 2) { // 좌
        if (ry < by) return 1;
        else return 0;
    } else { // 우
        if (ry > by) return 1;
        else return 0;
    }
}

void dfs(pair<int, int> r, pair<int, int> b, int cnt, int i) {
    bool r_flag = false, b_flag = false;
    int rx = r.first;
    int ry = r.second;
    int bx = b.first;
    int by = b.second;
    if (cnt > 10) {
        return;
    }
    int w = who_first(i, rx, ry, bx, by);
    if (w == 1) { // 빨 먼저
        while (true) { // 빨 굴리기
            if (map[rx + x[i]][ry + y[i]] == '#') break;
            if (map[rx + x[i]][ry + y[i]] == 'O') {
                r_flag = true;
                break;
            }
            rx += x[i];
            ry += y[i];
        }
        while (true) { // 파 굴리기
            if (map[bx + x[i]][by + y[i]] == '#')break;
            if (!r_flag && rx == bx + x[i] && ry == by + y[i]) break;
            if (map[bx + x[i]][by + y[i]] == 'O') {
                b_flag = true;
                break;
            }
            bx += x[i];
            by += y[i];
        }
    } else { // pa 먼저
        while (true) { // Pa 굴리기
            if (map[bx + x[i]][by + y[i]] == '#')break;
            if (map[bx + x[i]][by + y[i]] == 'O') {
                b_flag = true;
                break;
            }
            bx += x[i];
            by += y[i];
        }
        while (true) { // 빨 굴리기
            if (map[rx + x[i]][ry + y[i]] == '#')break;
            if (bx == rx + x[i] && by == ry + y[i]) break;
            if (map[rx + x[i]][ry + y[i]] == 'O') {
                r_flag = true;
                break;
            }
            rx += x[i];
            ry += y[i];
        }
    }
    if (b_flag) return;
    if (r_flag) {
        ans = min(ans, cnt);
        return;
    }
    for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        if (i == 0) {
            if (j == 1) continue;
        } else if (i == 1) {
            if (j == 0) continue;
        } else if (i == 2) {
            if (j == 3) continue;
        } else if (i == 3) {
            if (j == 2)continue;
        }
        dfs({rx, ry}, {bx, by}, cnt + 1, j);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') red = {i, j};
            if (map[i][j] == 'B') blue = {i, j};
        }
    }
    for (int i = 0; i < 4; i++) {
        dfs(red, blue, 1, i);
    }
    if (ans > 10) cout << -1;
    else cout << ans;
}