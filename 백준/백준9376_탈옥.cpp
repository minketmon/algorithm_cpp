#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 123456789
using namespace std;
int h, w, pcnt, dist0[105][105], dist1[105][105], dist2[105][105], temp[105][105];
int _x[] = {0, 0, -1, 1}, _y[] = {-1, 1, 0, 0};
char map[105][105];
pair<int, int> p1, p2;

void dijkstra(int x, int y, int (&dist)[105][105]) {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    dist[x][y] = 0;
    while (!pq.empty()) {
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        int cur_d = -pq.top().first;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + _x[i];
            int ny = cur_y + _y[i];
            int nd = cur_d;
            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
            if (map[nx][ny] == '*') continue;
            if (map[nx][ny] == '#') nd++;
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({-nd, {nx, ny}});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) { // 초기화, 초기화하는 값 확인
        pcnt = 0;
        memset(map, 0, sizeof(map));
        cin >> h >> w;
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) dist0[i][j] = INF, dist1[i][j] = INF, dist2[i][j] = INF;
        }
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) { // 외곽 초기화
                    map[i][j] = '.';
                    continue;
                }
                cin >> map[i][j];
                if (map[i][j] == '$') {
                    if (pcnt == 0) p1.first = i, p1.second = j, pcnt++;
                    else p2.first = i, p2.second = j;
                }
            }
        }
        dijkstra(0, 0, dist0);
        dijkstra(p1.first, p1.second, dist1);
        dijkstra(p2.first, p2.second, dist2);
        int _min = 10000;
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                temp[i][j] = dist0[i][j] + dist1[i][j] + dist2[i][j];
                if (map[i][j] == '#') temp[i][j] -= 2;
                _min = min(_min, temp[i][j]);
            }
        }
        cout << _min << '\n';
    }
}
