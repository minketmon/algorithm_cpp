#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int x[] = {0, 0, -1, 1}; // 좌 우 상 하
int y[] = {-1, 1, 0, 0};
char map[11][11];
pair<int, int> red, blue, finish;

int who_first(int dir, int rx, int ry, int bx, int by) {
    if (dir == 0) { // 좌
        if (ry < by) return 1;
        else return 0;
    } else if (dir == 1) { // 우
        if (ry > by) return 1;
        else return 0;
    } else if (dir == 2) { // 상
        if (rx < bx) return 1;
        else return 0;
    } else { // 하
        if (rx > bx) return 1;
        else return 0;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') red = {i, j};
            if (map[i][j] == 'B') blue = {i, j};
            if (map[i][j] == 'O') finish = {i, j};
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({red, blue});
    while (!q.empty()) {
        int red_x = q.front().first.first;
        int red_y = q.front().first.second;
        int blue_x = q.front().second.first;
        int blue_y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) { // 좌 우 상 하
            int num_first = who_first(i, red_x, red_y, blue_x, blue_y);
            if (num_first == 1) { // 빨 먼저
                // 구멍인 경우 처리
                while (map[red_x + x[i]][red_y + y[i]] != '#' && map[red_x + x[i]][red_y + y[i]] != 'B') {
                    red_x += x[i];
                    red_y += y[i];
                }
                if(map[red_x][red_y]=='O'){

                }
                while (map[blue_x + x[i]][blue_y + y[i]] != '#' && map[red_x + x[i]][red_y + y[i]] != 'R') {
                    blue_x += x[i];
                    blue_y += y[i];
                }
            } else { // 파 먼저
                while (map[blue_x + x[i]][blue_y + y[i]] != '#' && map[red_x + x[i]][red_y + y[i]] != 'R') {
                    blue_x += x[i];
                    blue_y += y[i];
                }
                while (map[red_x + x[i]][red_y + y[i]] != '#' && map[red_x + x[i]][red_y + y[i]] != 'B') {
                    red_x += x[i];
                    red_y += y[i];
                }
            }
        }
    }
}