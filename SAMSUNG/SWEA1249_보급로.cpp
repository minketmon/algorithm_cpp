#include <iostream>

using namespace std;
int n, ans, memo[101][101];
char map[101][101];
bool visited[101][101];
int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

void dfs(int a, int b, int cnt) {
    if (a == n && b == n) {
        ans = ans > cnt ? cnt : ans;
        return;
    }
    if (memo[a][b] != 0) {
        if (memo[a][b] > cnt) memo[a][b] = cnt;
        else return;
    } else memo[a][b] = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = a + x[i], ny = b + y[i];
        int nd = cnt + (map[nx][ny] - '0');
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (visited[nx][ny]) continue;
        if (nd > ans) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, nd);
        visited[nx][ny] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        ans = 987654321;
        memset(map, 0, sizeof(map)), memset(visited, 0, sizeof(visited));
        memset(memo, 0, sizeof(memo));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }
        visited[1][1] = true;
        dfs(1, 1, 0);
        cout << '#' << tc << ' ' << ans << '\n';
    }
}