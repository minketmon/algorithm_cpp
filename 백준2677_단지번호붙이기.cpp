#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, -1, 1};
int n, arr[26][26], ans[100], cnt;
bool visited[26][26];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + _x[i];
            int ny = cur_y + _y[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (arr[nx][ny] == 1) q.push({nx, ny});
        }
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<pair<int, int>> yes;
    vector<int> res;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
            if(arr[i][j] == 1) yes.push_back({i, j});
        }
    }
    for (auto a: yes) {
        if (visited[a.first][a.second]) continue;
        res.push_back(bfs(a.first, a.second));
        cnt = 0;
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto a: res) cout << a << '\n';
}