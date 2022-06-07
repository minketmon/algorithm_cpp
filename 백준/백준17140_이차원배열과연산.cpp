#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int row = 3, col = 3;
int r, c, k, t, map[102][102], num_cnt[101];
vector<int> v;

vector<int> sort_func(vector<int> vec) {
    vector<pair<int, int>> p; // 횟수, 숫자
    vector<int> res;
    int cnt = 0;
    memset(num_cnt, 0, sizeof(num_cnt));
    for (int i: vec) num_cnt[i]++;
    for (int i = 1; i < 101; i++)
        if (num_cnt[i] != 0) cnt++, p.push_back({num_cnt[i], i});
    sort(p.begin(), p.end());
    for (int i = 0; i < cnt; i++)
        res.push_back(p[i].second), res.push_back(p[i].first);
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> r >> c >> k;
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> map[i][j];
        }
    }
    while (true) {
        if (map[r][c] == k) break;
        if (t > 100) {
            cout << -1;
            return 0;
        }
        if (row >= col) {
            int col_max = 0;
            for (int i = 1; i <= row; i++) {
                v.clear();
                for (int j = 1; j <= col; j++) {
                    v.push_back(map[i][j]);
                    map[i][j] = 0;
                }
                vector<int> res;
                res = sort_func(v);
                for (int j = 0; j < res.size(); j++) {
                    map[i][j + 1] = res[j];
                }
                int sz = res.size();
                col_max = max(col_max, sz);
            }
            col = col_max;
        } else {
            int row_max = 0;
            vector<vector<int>> temp;
            for (int i = 1; i <= col; i++) {
                v.clear();
                for (int j = 1; j <= row; j++) {
                    v.push_back(map[j][i]);
                    map[j][i] = 0;
                }
                vector<int> res;
                res = sort_func(v);
                temp.push_back(res);
                int sz = res.size();
                row_max = max(row_max, sz);
            }
            for (int i = 0; i < temp.size(); i++) {
                for (int j = 0; j < temp[i].size(); j++) {
                    map[j + 1][i + 1] = temp[i][j];
                }
            }
            row = row_max;
        }
        t++;
    }
    cout << t;
}