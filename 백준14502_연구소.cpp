#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[9][9];
int temp[9][9];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
int n, m;
bool visited[9][9];
int answer = 0;
vector<pair<int, int>> zero, virus;

void bfs(int _x, int _y) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[_x][_y] = true;
    q.push({_x, _y});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = cur_x + x[i];
            int dy = cur_y + y[i];
            if (dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1) continue;
            if (visited[dx][dy] == false && temp[dx][dy] == 0) {
                temp[dx][dy] = 2; //바이러스 전파
                visited[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }
}

void combination(int idx, int cnt) {
    if (cnt == 3) {
//        //bfs로 안전지대가 몇인지 확인
//        //바이러스 위치 저장
//        //바이러스를 bfs돌려서 퍼트리고 난 후에 안전지대 확인

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = map[i][j];
            }
        }

        int zero_cnt = 0;
        for (int i = 0; i < virus.size(); i++) {
            bfs(virus[i].first, virus[i].second);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 0) zero_cnt++;
            }
        }
        answer = max(answer, zero_cnt);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                combination(idx, cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) zero.push_back({i, j});
            if (map[i][j] == 2) virus.push_back({i, j});
        }
    }
    combination(0, 0);
    cout << answer;
}