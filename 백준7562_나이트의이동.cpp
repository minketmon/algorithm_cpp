#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visited[302][302];

int x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, l, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        bool flag = false;
        queue<pair<int, int>> q;
        cin >> l;
        cin >> x1 >> y1 >> x2 >> y2;
        q.push({x1, y1});
        if (x1 == x2 && y1 == y2) {
            cout << 0 << "\n";
            continue;
        }

        visited[x1][y1] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur_x = q.front().first;
                int cur_y = q.front().second;
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int dx = cur_x + x[i];
                    int dy = cur_y + y[i];
                    if (dx == x2 && dy == y2) { // 도착
                        flag = true;
                        break;
                    }
                    if (dx < 0 || dy < 0 || dx > l - 1 || dy > l - 1) continue;
                    if (!visited[dx][dy]) {
                        q.push({dx, dy});
                        visited[dx][dy] = true;
                    }
                }
                if (flag) break;
            }
            if (flag) {
                cout << cnt + 1 << "\n";
                break;
            }
            cnt++;
        }
    }

}