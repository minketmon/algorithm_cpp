#include <iostream>

using namespace std;
int r, c, arr[21][21], alpha[30], ans;
int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt) {
    ans = ans < cnt ? cnt : ans;
    for (int i = 0; i < 4; i++) {
        int nx = x + _x[i];
        int ny = y + _y[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (alpha[arr[nx][ny]]) continue;
        alpha[arr[nx][ny]] = true;
        dfs(nx, ny, cnt + 1);
        alpha[arr[nx][ny]] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - 'A';
        }
    }
    alpha[arr[0][0]] = true;
    dfs(0, 0, 0);
    cout << ++ans;
}