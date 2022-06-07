#include <iostream>
#include <vector>
#include <queue>

#define INF 123456789
using namespace std;

int n, m, t, d, map[26][26], dist[26][26], dist2[26][26];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            dist[i][j] = INF, dist2[i][j] = INF;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c >= 'A' && c <= 'Z')
                map[i][j] = c - 'A';
            else
                map[i][j] = c - 'a' + 26;
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while (!pq.empty()) {
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1)continue;
            if (abs(map[nx][ny] - map[cur_x][cur_y]) > t) continue;
            if (map[nx][ny] <= map[cur_x][cur_y]) { // 작거나 같으면 높이는 1
                if (dist[nx][ny] > dist[cur_x][cur_y] + 1) {
                    dist[nx][ny] = dist[cur_x][cur_y] + 1;
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            } else { // 크면 높이는 갭*갭
                int gap = abs(map[nx][ny] - map[cur_x][cur_y]);
                int p = gap * gap;
                if (dist[nx][ny] > dist[cur_x][cur_y] + p) {
                    dist[nx][ny] = dist[cur_x][cur_y] + p;
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    dist2[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1)continue;
            if (abs(map[nx][ny] - map[cur_x][cur_y]) > t) continue;
            if (map[cur_x][cur_y] > map[nx][ny]) {
                int gap = abs(map[nx][ny] - map[cur_x][cur_y]);
                int p = gap * gap;
                if (dist2[nx][ny] > dist2[cur_x][cur_y] + p) {
                    dist2[nx][ny] = dist2[cur_x][cur_y] + p;
                    pq.push({-dist2[nx][ny], {nx, ny}});
                }
            } else {
                if (dist2[nx][ny] > dist2[cur_x][cur_y] + 1) {
                    dist2[nx][ny] = dist2[cur_x][cur_y] + 1;
                    pq.push({-dist2[nx][ny], {nx, ny}});
                }
            }
        }
    }
    int _max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == INF || dist2[i][j] == INF) continue;
            if (dist[i][j] + dist2[i][j] <= d)
                _max = max(_max, map[i][j]);
        }
    }
    cout << _max << "\n";
}