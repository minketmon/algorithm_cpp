#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m, answer = 0;
int map[8][8];
int temp[8][8];
bool visited[8][8];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
vector<pair<int, int>> virus;

void bfs(int _x, int _y) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[_x][_y] = true;
    q.push({_x, _y});
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int new_x = cur_x + x[i];
            int new_y = cur_y + y[i];
            if(new_x < 0 || new_y < 0 || new_x > n-1 || new_y > m-1) continue;
            if(temp[new_x][new_y] == 0 && visited[new_x][new_y]==false) {
                visited[new_x][new_y] = true;
                temp[new_x][new_y] = 2;
                q.push({new_x, new_y});
            }
        }
    }
}

void combination(int idx, int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                temp[i][j] = map[i][j];
        }
        for (int i = 0; i < virus.size(); i++)
            bfs(virus[i].first, virus[i].second);

        int zero_cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                if (temp[i][j] == 0) zero_cnt++;
        }

        answer = max(answer, zero_cnt);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                combination(i, cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) virus.push_back({i, j});
        }
    }
    combination(0, 0);
    cout << answer;
}