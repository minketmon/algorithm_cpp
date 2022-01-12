#include <cstring>
#include <vector>

#define MISS        0
#define CARRIER        1
#define BATTLESHIP    2
#define CRUISER        3
#define SUBMARINE    4
#define DESTROYER    5
using namespace std;

extern int fire(int r, int c);

int map[10][10], cnt[5], mass[5] = {5, 4, 3, 3, 2};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> loc[5];

void init(int limit) {

}

void play() {
    memset(map, -1, sizeof(map));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 5; i++) loc[i].clear();

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if ((i + j) % 2) continue;
            map[i][j] = fire(i, j);
            if (map[i][j] > 0) {
                loc[map[i][j] - 1].push_back({i, j});
                cnt[map[i][j] - 1]++;
            }
        }
    }

    // CARRIER, BATTLESHIP
    for (int s = 0; s < 2; s++) {
        bool flag = false;
        if (loc[s][0].second == loc[s][1].second) { // 세로 방향
            int i = loc[s][0].first;
            int j = loc[s][0].second;
            for (int x = i + 1; x < 10; x++) {
                if (cnt[s] == mass[s]) break;
                if (map[x][j] == -1) {
                    map[x][j] = fire(x, j);
                    if (map[x][j]) {
                        loc[map[x][j] - 1].push_back({x, j});
                        cnt[map[x][j] - 1]++;
                    }
                }
                if (map[x][j] != s + 1) break;
            }
            for (int x = i - 1; x >= 0; x--) {
                if (cnt[s] == mass[s]) break;
                if (map[x][j] == -1) {
                    map[x][j] = fire(x, j);
                    if (map[x][j]) {
                        loc[map[x][j] - 1].push_back({x, j});
                        cnt[map[x][j] - 1]++;
                    }
                }
                if (map[x][j] != s + 1) break;
            }
        } else { //가로 방향
            int i = loc[s][0].first;
            int j = loc[s][0].second;
            for (int x = j + 1; x < 10; x++) {
                if (cnt[s] == mass[s]) break;
                if (map[i][x] == -1) {
                    map[i][x] = fire(i, x);
                    if (map[i][x]) {
                        loc[map[i][x] - 1].push_back({i, x});
                        cnt[map[i][x] - 1]++;
                    }
                }
                if (map[i][x] != s + 1) break;
            }
            for (int x = j - 1; x >= 0; x--) {
                if (cnt[s] == mass[s]) break;
                if (map[i][x] == -1) {
                    map[i][x] = fire(i, x);
                    if (map[i][x]) {
                        loc[map[i][x] - 1].push_back({i, x});
                        cnt[map[i][x] - 1]++;
                    }
                }
                if (map[i][x] != s + 1) break;
            }
        }

    }

    // CRUSIER, SUBMARINE
    for (int s = 2; s < 4; s++) {
        for (int i = 0; i < loc[s].size(); i++) {
            if (cnt[s] == mass[s]) break;
            int x = loc[s][i].first;
            int y = loc[s][i].second;
            for (int dir = 0; dir < 4; dir++) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (xx < 0 || yy < 0 || xx > 9 || yy > 9) continue;
                if (map[xx][yy] == -1) {
                    map[xx][yy] = fire(xx, yy);
                    if (map[xx][yy]) {
                        loc[map[xx][yy] - 1].push_back({xx, yy});
                        cnt[map[xx][yy] - 1]++;
                    }
                }
            }
        }
    }

    //DESTROYER
    if (cnt[4] == 2) return;
    int x = loc[4][0].first;
    int y = loc[4][0].second;
    for (int dir = 0; dir < 4; dir++) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (xx < 0 || yy < 0 || xx > 9 || yy > 9) continue;
        if (map[xx][yy] == -1) {
            map[xx][yy] = fire(xx, yy);
            if (map[xx][yy] == DESTROYER) break;
        }
    }
}