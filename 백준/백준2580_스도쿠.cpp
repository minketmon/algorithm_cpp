#include <iostream>
#include <vector>

using namespace std;
int arr[10][10];
vector<pair<int, int>> zero;

void dfs(int idx) {
    if (idx == zero.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    int x = zero[idx].first;
    int y = zero[idx].second;
    bool row[10] = {false,}, col[10] = {false,}, sq[10] = {false,};
    for (int i = 0; i < 9; i++) row[arr[x][i]] = true, col[arr[i][y]] = true;
    int nx = x / 3 * 3, ny = y / 3 * 3;
    for (int i = nx; i < nx + 3; i++) {
        for (int j = ny; j < ny + 3; j++) {
            sq[arr[i][j]] = true;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (row[i] || col[i] || sq[i]) continue;
        arr[x][y] = i;
        dfs(idx + 1);
        arr[x][y] = 0;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) zero.push_back({i, j});
        }
    }
    dfs(0);
}
