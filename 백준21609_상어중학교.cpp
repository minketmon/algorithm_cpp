#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
int n, m, map[21][21], score, group[21][21];
int _x[] = {0, 0, -1, 1};
int _y[] = {-1, 1, 0, 0};
bool visit[21][21];
bool flag = false;


pair<int, int> find_block(int a, int b, int num) {
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    q.push({a, b});
    int color = map[a][b];
    visit[a][b] = true;
    group[a][b] = num;
    int block_count = 0, rainbow_count = 0;
    block_count++;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        //bfs를 통해 group탐색
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = cur_x + _x[i];
                int ny = cur_y + _y[i];
                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if (map[nx][ny] == -1 || visit[nx][ny]) continue;
                if (map[nx][ny] == 0 || map[nx][ny] == color) {
                    if (map[nx][ny] == 0) rainbow_count++;
                    else group[nx][ny] = num;
                    block_count++;
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return make_pair(block_count, rainbow_count);
}

void find_group() {
    memset(group, 0, sizeof(group));
    int block_size = 0, rainbow_size = 0;
    pair<int, int> standard = {0, 0};
    int idx = 1;
    vector<pair<int, int>> biggest_group;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // grouping을 하며 가장 큰 그룹 갱신
            if (group[i][j] > 0) continue;
            if (map[i][j] < 1) continue;
            pair<int, int> ret = find_block(i, j, idx);
            idx++;
            if (block_size < ret.first) {
                block_size = ret.first;
                rainbow_size = ret.second;
                standard = {i, j};
            } else if (block_size == ret.first && rainbow_size < ret.second) {
                block_size = ret.first;
                rainbow_size = ret.second;
                standard = {i, j};
            } else if (block_size == ret.first && rainbow_size == ret.second) {
                block_size = ret.first;
                rainbow_size = ret.second;
                standard = {i, j};
            }
        }
    }
    if (block_size < 2) {
        //크기가 2보다 작은 경우 처리
        flag = true;
        return;
    }
    score += block_size * block_size;
    // 가장 큰 블록 그룹에 속하는 블록들 지워주기
    queue<pair<int, int>> q;
    q.push({standard.first, standard.second});
    int color = map[standard.first][standard.second];
    map[standard.first][standard.second] = -2;
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + _x[i];
            int ny = cur_y + _y[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (map[nx][ny] < 0) continue;
            if (map[nx][ny] == color || map[nx][ny] == 0) {
                map[nx][ny] = -2;
                q.push({nx, ny});
            }
        }
    }
}

void gravity() {
    int temp[21][21];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = -2;
        }
    }
    for (int i = 1; i <= n; i++) {
        stack<int> st;
        for (int j = 1; j <= n; j++) {
            if (map[j][i] >= 0) st.push(map[j][i]);
            else if (map[j][i] == -1) {
                temp[j][i] = -1;
                int idx = j - 1;
                while (!st.empty()) {
                    temp[idx][i] = st.top();
                    st.pop();
                    idx--;
                }
            }
        }
        int idx = n;
        while (!st.empty()) {
            temp[idx][i] = st.top();
            st.pop();
            idx--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void rotation() {
    int temp[21][21];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = map[j][n - i + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    while (true) {
        if (flag) break;
        find_group();
        // 중력 발동 - 아이돈노우
        gravity();
        // 90도 회전
        rotation();
        gravity();
    }
    cout << score;
}