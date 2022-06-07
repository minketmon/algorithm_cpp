#include <iostream>

using namespace std;
int n, m, k, ans;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
bool visited[6][6];
char map[6][6];
pair<int, int> start;

void dfs(int a, int b, int cnt) {
    if (cnt == k && a == 1 && b == m) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = a + x[i];
        int ny = b + y[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (map[nx][ny] == 'T') continue;;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, cnt + 1);
        visited[nx][ny] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    start = {n, 1};
    visited[start.first][start.second] = true;
    dfs(start.first, start.second, 1);
    cout << ans;
}