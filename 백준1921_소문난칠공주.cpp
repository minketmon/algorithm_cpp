#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
char map[26][26];
int temp[26][26];
bool visited[26][26];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
int ans, cnt, s_cnt, d_cnt;
vector<int> v;
bool s[1001];

bool bfs(int a, int b) {
    queue<pair<int, int>> q;
    cnt = 0;
    visited[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        int zero_cnt = 0, out_cnt = 0;
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > 4 || ny > 4) {
                out_cnt++;
                continue;
            }
            if (temp[cur_x][cur_y] == 1 && temp[nx][ny] == 0) {
                zero_cnt++;
            }
            if (zero_cnt >= 4 - out_cnt) return false;
            if (visited[nx][ny] == true) continue;
            if (temp[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    if (cnt < 7) return false;
    return true;
}

void dfs(int idx, int cnt) {
    if (cnt == 7) {
        int a, b;
        s_cnt = 0;
        d_cnt = 0;
        memset(temp, 0, sizeof(temp));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 25; i++) {
            if (s[i] == true) { // 조합 뽑음 25C7
                if (map[i / 5][i % 5] == 'S') s_cnt++;
                else d_cnt++;
                temp[i / 5][i % 5] = 1;
                a = i / 5;
                b = i % 5;
            }
        }
        if (s_cnt < 4) return; // 다솜파가 4명 미만인거 거름
        if (bfs(a, b) == true)
            ans++;
        return;
    }

    for (int i = idx; i < 25; i++) {
        if (s[i] == true) continue;
        s[i] = true;
        dfs(i, cnt + 1);
        s[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 25; i++)v.push_back(i);
    dfs(0, 0);
    cout << ans;
}