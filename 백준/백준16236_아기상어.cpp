#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, cnt, fish_cnt;
int map[21][21], visited[21][21];
int baby_size = 2;
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
vector<pair<int, int>> v;
pair<int, int> cur;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    map[a][b] = 0;
    visited[a][b] = 0;
    q.push({a, b});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
            if (map[nx][ny] > baby_size) continue;
            if (visited[nx][ny] != -1) continue;
            if (map[nx][ny] == baby_size || map[nx][ny] == 0) { // 지나가는 경우
                visited[nx][ny] = visited[cur_x][cur_y] + 1;
            }
            else if(map[nx][ny] < baby_size && map[nx][ny] > 0)  { // 물고가 먹을 수 있는 길
                visited[nx][ny] = visited[cur_x][cur_y] + 1;
                v.push_back({nx, ny});
            }
            q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) cur = {i, j};
        }
    }

    while (true) {
        if (fish_cnt >= baby_size) {
            fish_cnt -= baby_size;
            baby_size++;
        }
        memset(visited, -1, sizeof(visited));
        v.clear();
        bfs(cur.first, cur.second);
        if (v.size() == 0) {
            cout << cnt << "\n";
            break;
        } else if (v.size() == 1) {
            int a, b;
            a = v[0].first;
            b = v[0].second;
            map[a][b] = 0;
            cnt += visited[a][b];
            fish_cnt++;
            cur = {a, b};
        } else {
            int min_cnt = 1000;
            vector<pair<int, int>> select;
            for (auto a: v) {
                min_cnt = min(min_cnt, visited[a.first][a.second]);
            }
            for (auto a: v) {
                if (visited[a.first][a.second] == min_cnt) {
                    select.push_back({a.first, a.second});
                }
            }
            sort(select.begin(), select.end());
            int a, b;
            a = select[0].first;
            b = select[0].second;
            map[a][b] = 0;
            cnt += visited[a][b];
            fish_cnt++;
            cur = {a, b};
        }
    }
}