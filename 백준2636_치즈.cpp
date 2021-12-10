#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, m, cnt;
int map[101][101], temp[101][101];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
bool visited[101][101];
bool visited2[101][101];

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    visited[a][b] = true;
    map[a][b] = 2;
    q.push({a, b});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
            if (visited[nx][ny] == false && map[nx][ny] != 1) {
                visited[nx][ny] = true;
                map[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

void bfs2(int a, int b) {
    queue<pair<int, int>> q;
    visited2[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int out_cnt = 0;
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1) continue;
            if (visited2[nx][ny] == false && map[nx][ny] == 2) {
                out_cnt++;
                visited2[nx][ny] = true;
            }
            if (out_cnt > 0) map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(true) {
        int c_cnt=0;
        bfs(0,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                cout << map[i][j] << " ";
            }cout << "\n";
        }
        cout << "=====\n";
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j]==1) c_cnt++;
            }
        }
        if(c_cnt==0) break;
        memset(visited2, 0, sizeof(visited2));
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                //cout << map[i][j] << " ";
                if(map[i][j]==1){
                    cout << "ij:" << i << " " << j << "\n";
                    bfs2(i, j);
                }

            }//cout << "\n";
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                cout << map[i][j] << " ";
            }cout << "\n";
        }
        cnt++;
    }

}