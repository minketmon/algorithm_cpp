#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF 123456789
using namespace std;

struct Cross {
    int dir, a, b;

    Cross(int _d, int _a, int _b) {
        dir = _d;
        a = _a;
        b = _b;
    }
};

struct Car {
    int x, y;
};

int n, m, cross_cnt;
bool res;
int x[] = {0, 0, -1, 1}; // 좌 우 상 하
int y[] = {-1, 1, 0, 0};
int dist[21][21];
char map[21][21];
vector<Cross> cross;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));
        cross_cnt = 0;
        res = false;
        priority_queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) dist[i][j] = INF;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'A') {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                } else if (0 <= map[i][j] - '0' && map[i][j] - '0' < 10) {
                    cross_cnt++;
                }
            }
        }
        for (int i = 0; i < cross_cnt; i++) {
            int num, a, b;
            char dir;
            cin >> num >> dir >> a >> b;
            if (dir == '-')
                cross.emplace_back(-1, a, b);
            else cross.emplace_back(1, a, b);
        }

        while (!q.empty()) {
            int cur_t = -q.top().first;
            int cur_x = q.top().second.first;
            int cur_y = q.top().second.second;
            q.pop();
            if (map[cur_x][cur_y] == 'B') { // finish
                cout << cur_t << "\n";
                res = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nt = cur_t + 1;
                int nx = cur_x + x[i];
                int ny = cur_y + y[i];

                if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
                if (map[nx][ny] == '.') continue;
                if (map[nx][ny] - '0' >= 0 && map[nx][ny] - '0' < 10) { // 교차로이면 얼마나 기다려야되는지 계산을 그때그때
                    int num = map[nx][ny] - '0';
                    while (true) {
                        int mod = nt % (cross[num].a + cross[num].b);
                        if (mod == 0) mod = cross[num].a + cross[num].b;
                        if (cross[num].dir == -1) { // 가로가 먼저 켜지는 신호등
                            if (mod <= cross[num].a) { // 가로방향 신호등 on
                                if (i == 0 || i == 1) break;
                            } else { // 세로방향 신호등 on
                                if (i == 2 || i == 3) break;
                            }
                        } else if (cross[num].dir == 1) { // 세로가 먼저 켜지는 신호등
                            if (mod <= cross[num].b) { // 세로방향 신호등 on
                                if (i == 2 || i == 3) break;
                            } else { // 가로방향 신호등 on
                                if (i == 0 || i == 1) break;
                            }
                        }
                        nt++;
                    }
                }
                if (dist[nx][ny] <= nt) continue;
                dist[nx][ny] = nt;
                q.push({-nt, {nx, ny}});
            }
        }
        if (!res) cout << "impossible\n";
    }
}