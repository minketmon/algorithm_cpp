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