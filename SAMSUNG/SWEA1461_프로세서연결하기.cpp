#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n, map[13][13], ans, _max;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
vector<pair<int, int>> v;

void dfs(int idx, int core, int wire) {
    if (idx == v.size()) {
        if (core == _max)
            ans = ans > wire ? wire : ans;
        else if (core > _max) {
            _max = core;
            ans = wire;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = v[idx].first, ny = v[idx].second, mx = v[idx].first, my = v[idx].second, cnt = 0;
        while (true) {
            nx += x[i], ny += y[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
            if (map[nx][ny] == 1) {
                cnt = 0;
                break;
            }
            cnt++;
        }
        for (int j = 0; j < cnt; j++) {
            mx += x[i], my += y[i];
            map[mx][my] = 1;
        }
        if (cnt == 0) {
            dfs(idx + 1, core, wire);
        } else {
            dfs(idx + 1, core + 1, wire + cnt);
            mx = v[idx].first, my = v[idx].second;
            for (int k = 0; k < cnt; k++) {
                mx += x[i], my += y[i];
                map[mx][my] = 0;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int t, tc;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        v.clear();
        memset(map, 0, sizeof(map));
        ans = 0, _max = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                if (map[i][j] == 1 && (i != 0 && i != n - 1 && j != 0 && j != n - 1)) v.push_back({i, j});
            }
        }
        dfs(0, 0, 0);
        cout << '#' << tc << ' ' << ans << '\n';
    }
}