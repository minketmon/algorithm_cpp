#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int*> map;
int n, m;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void rotateMatrix(int k) {
    int tmp = 2 * n + 2 * m - 4;
    k %= tmp;
    if (!k) return;
    queue<int> q;
    for (int j = 0; j < m - 1; j++)
        q.push(map[0][j]);
    for (int i = 0; i < n - 1; i++)
        q.push(map[i][m - 1]);
    for (int j = m - 1; j > 0; j--)
        q.push(map[n - 1][j]);
    for (int i = n - 1; i > 0; i--)
        q.push(map[i][0]);

    int i, j, dir;
    if (k <= m - 1) {
        i = 0, j = k;
        dir = 0;
    } else if (k <= n + m - 2) {
        i = k - m + 1, j = m - 1;
        dir = 1;
    } else if (k <= n + 2 * m - 3) {
        i = n - 1, j = (m - 1) - (k - n - m +2);
        dir = 2;
    } else {
        i = 2 * n + 2 * m - 4 - k, j = 0;
        dir = 3;
    }
    while (!q.empty()) {
        map[i][j] = q.front();
        q.pop();
        if (!dir && j == m-1)
            dir = 1;
        else if (dir == 1 && i == n-1)
            dir = 2;
        else if (dir == 2 && !j)
            dir = 3;
        else if (dir == 3 && !i)
            dir = 0;
        i += di[dir];
        j += dj[dir];
    }
}

void shiftRows(int k) {
    k %= n;
    if (!k) return;
    vector<int*> v;
    v.resize(n);
    for (int i = 0; i < n; i++)
        v[(i + k) % n] = map[i];

    for (int i = 0; i < n; i++)
        map[i] = v[i];
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    n = rc.size(), m = rc[0].size();
    map.resize(n);
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        for (int j = 0; j < m; j++) {
            map[i][j] = rc[i][j];
        }
    }
    int r_cnt = 0, s_cnt = 0;
    for (string op : operations) {
        if (op[0] == 'R') {
            if (s_cnt)
                shiftRows(s_cnt);
            s_cnt = 0;
            r_cnt++;
        } else {
            if (r_cnt)
                rotateMatrix(r_cnt);
            r_cnt = 0;
            s_cnt++;
        }
    }
    if (s_cnt)
        shiftRows(s_cnt);
    else if (r_cnt)
        rotateMatrix(r_cnt);

    vector<vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        for (int j = 0; j < m; j++) {
            v[i][j] = map[i][j];
        }
    }
    return v;
}