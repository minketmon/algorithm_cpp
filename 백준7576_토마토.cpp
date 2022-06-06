#include <iostream>
#include <queue>

using namespace std;
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
int tomato[1001][1001];
queue<pair<int, int>> q;

int main() {
    int cnt = 0;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, n, num;
    int count = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            tomato[i][j] = num;
            if (tomato[i][j]) cnt++;
            if (num == 1) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = cur_x + x[i];
                int dy = cur_y + y[i];
                if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
                if (!tomato[dx][dy]) {
                    q.push({dx, dy});
                    cnt++;
                    tomato[dx][dy] = count + 1;
                }
            }
        }
        count++;
    }
    if (m * n == cnt) {
        cout << count - 1;
    } else {
        cout << -1;
    }
}

/* 220607
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, arr[1001][1001], visited[1001][1001], cnt, day;
int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, -1, 1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    queue<pair<int, int>> q;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) q.push({i, j});
        }
    }
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cx + _x[i], ny = cy + _y[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (!arr[nx][ny]) {
                    arr[nx][ny] = day + 1;
                    q.push({nx, ny});
                }
            }
        }
        day++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day - 1;
}
 */