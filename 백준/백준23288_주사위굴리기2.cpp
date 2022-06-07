#include <iostream>
#include <queue>

using namespace std;
int n, m, k, map[21][21], d = 4, xp = 1, yp = 1, total; //d : 상1 하2 좌3 우4
int score[21][21], dice[7] = {2, 4, 1, 3, 5, 6};
bool check[21][21];
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

void move(int dir) { // x,y 좌표 바꿔주고, 주사위 도면 바꾸기
    int temp[7];
    if (dir == 1) xp--; // 상
    else if (dir == 2) xp++; // 하
    else if (dir == 3) yp--; // 좌
    else if (dir == 4) yp++; // 우
    for (int i = 0; i < 7; i++) temp[i] = dice[i];
    if (dir == 1) { // 위굴
        temp[0] = dice[2];
        temp[2] = dice[4];
        temp[4] = dice[5];
        temp[5] = dice[0];
    } else if (dir == 2) { // 아굴
        temp[0] = dice[5];
        temp[2] = dice[0];
        temp[4] = dice[2];
        temp[5] = dice[4];
    } else if (dir == 3) { // 왼굴
        temp[1] = dice[2];
        temp[2] = dice[3];
        temp[3] = dice[5];
        temp[5] = dice[1];
    } else if (dir == 4) { // 오굴
        temp[1] = dice[5];
        temp[2] = dice[1];
        temp[3] = dice[2];
        temp[5] = dice[3];
    }
    for (int i = 0; i < 7; i++) dice[i] = temp[i];
}

void score_board(int a, int b) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    v.push_back({a, b});
    bool visited[21][21] = {false,};
    q.push({a, b});
    visited[a][b] = true;
    int cnt = 1;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (visited[nx][ny]) continue;
            if (map[cur_x][cur_y] != map[nx][ny]) continue;
            visited[nx][ny] = true;
            check[nx][ny] = true;
            v.push_back({nx, ny});
            cnt++;
            q.push({nx, ny});
        }
    }
    for (auto &i: v) {
        score[i.first][i.second] = cnt;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!check[i][j]) score_board(i, j);
        }
    }
    while (k--) {
        move(d);
        if (xp < 1 || yp < 1 || xp > n || yp > m) { // 범위 벗어나면 반대방향으로 두번
            if (d == 1) {
                move(2);
                move(2);
                d = 2;
            } else if (d == 2) {
                move(1);
                move(1);
                d = 1;
            } else if (d == 3) {
                move(4);
                move(4);
                d = 4;
            } else {
                move(3);
                move(3);
                d = 3;
            }
        }
        int t = map[xp][yp] * score[xp][yp];
        total += t;
        int a = dice[5];
        int b = map[xp][yp];
        if (a > b) { // 시계방향
            if (d == 1) d = 4;
            else if (d == 4) d = 2;
            else if (d == 2) d = 3;
            else if (d == 3) d = 1;
        } else if (a < b) { // 반시계방향
            if (d == 1) d = 3;
            else if (d == 3) d = 2;
            else if (d == 2) d = 4;
            else if (d == 4) d = 1;
        }
    }
    cout << total;
}