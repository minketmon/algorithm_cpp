#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int n, m, d, round, _max, map[17][17], temp[17][17];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
bool visited[17], visited2[17][17];
vector<int> v;
vector<pair<int, int>> k;
vector<pair<int, pair<int, int>>> kill;

void fight(pair<int, int> goonsu) {
    memset(visited2, 0, sizeof(visited2));
    queue<pair<int, int>> q;
    int dist = 123456789;
    int res_x = 0, res_y = 0, res_dist = 123456789;
    q.push(goonsu);
    visited2[goonsu.first][goonsu.second] = true;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            dist = abs(nx - goonsu.first) + abs(ny - goonsu.second);
            if (dist > d) continue;
            if (visited2[nx][ny]) continue;
            if (nx > n - round || nx < 1 || ny < 1 || ny > m) continue;
            q.push({nx, ny});
            visited2[nx][ny] = true;
            if (temp[nx][ny] == 1) {
                if (res_x == 0 && res_y == 0) res_x = nx, res_y = ny, res_dist = dist;
                if (dist < res_dist) res_x = nx, res_y = ny, res_dist = dist;
                if (dist == res_dist) {
                    if (ny < res_y) res_x = nx, res_y = ny, res_dist = dist;
                }
            }
        }
    }
    if (res_dist != 123456789)
        k.push_back({res_x, res_y});
}

void combination(int idx, int cnt) {
    if (cnt == 3) {
        round = 0;
        int f_cnt = 0;
        k.clear();
        vector<pair<int, int>> g;
        for (int i = 0; i < m; i++) {
            if (visited[i]) g.push_back({n - round + 1, i + 1});
        }
        // 배치된 궁수로 라운드 끝까지 돌기
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= n - round; i++) {
            for (int j = 1; j <= m; j++) {
                temp[i][j] = map[i][j];
                if (temp[i][j] == 1) f_cnt++;
            }
        }
        if(f_cnt==0) return;
        while (round <= n) {
            for (auto a: g) temp[a.first][a.second] = 2;
            for (int k = 0; k < 3; k++) {
                pair<int, int> goongsu = {g[k].first, g[k].second};
                fight(goongsu);
            }
            for (auto a: k)
                temp[a.first][a.second] = 0;
            for (int i = 0; i < 3; i++)
                g[i].first -= 1;
            round++;
        }
        k.erase(unique(k.begin(), k.end()), k.end());
        int sz = k.size();
        _max = max(_max, sz);
        return;
    }
    for (int i = idx; i < m; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        combination(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= m; i++) v.push_back(i);
    combination(0, 0);
    cout << _max;
}