#include <iostream>
#include <queue>

using namespace std;
int map[2500], imap[50][50];
int n, m, d[101], s[101], sc1, sc2, sc3;
pair<int, int> shark;

void destroy(int i) {
    if (d[i] == 1) { // 상
        for (int j = 1; j <= s[i]; j++) {
            imap[shark.first - j][shark.second] = 0;
        }
    } else if (d[i] == 2) { // 하
        for (int j = 1; j <= s[i]; j++) {
            imap[shark.first + j][shark.second] = 0;
        }
    } else if (d[i] == 3) { // 좌
        for (int j = 1; j <= s[i]; j++) {
            imap[shark.first][shark.second - j] = 0;
        }
    } else if (d[i] == 4) { // 우
        for (int j = 1; j <= s[i]; j++) {
            imap[shark.first][shark.second + j] = 0;
        }
    }
}

void straight() {
    map[0] = imap[shark.first][shark.second];
    int xp = shark.first, yp = shark.second; // 3, 3
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (idx >= n * n) break;
        if (i % 2 == 1) {
            for (int j = 1; j <= i; j++) {
                yp--;
                map[idx] = imap[xp][yp];
                idx++;
            }
            for (int j = 1; j <= i; j++) {
                xp++;
                map[idx] = imap[xp][yp];
                idx++;
            }
        } else {
            for (int j = 1; j <= i; j++) {
                yp++;
                map[idx] = imap[xp][yp];
                idx++;
            }
            for (int j = 1; j <= i; j++) {
                xp--;
                map[idx] = imap[xp][yp];
                idx++;
            }
        }
    }
}

void to_map() {
    imap[shark.first][shark.second] = map[0];
    int xp = shark.first, yp = shark.second; // 3, 3
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (idx >= n * n) break;
        if (i % 2 == 1) {
            for (int j = 1; j <= i; j++) {
                yp--;
                imap[xp][yp] = map[idx];
                idx++;
            }
            for (int j = 1; j <= i; j++) {
                xp++;
                imap[xp][yp] = map[idx];
                idx++;
            }
        } else {
            for (int j = 1; j <= i; j++) {
                yp++;
                imap[xp][yp] = map[idx];
                idx++;
            }
            for (int j = 1; j <= i; j++) {
                xp--;
                imap[xp][yp] = map[idx];
                idx++;
            }
        }
    }
}

void move() {
    int temp[2500] = {0,};
    queue<int> q;
    for (int i = 1; i < n * n; i++) {
        if (map[i] > 0) {
            q.push(map[i]);
        }
    }
    int idx = 1;
    while (!q.empty()) {
        temp[idx] = q.front();
        q.pop();
        idx++;
    }
    for (int i = 0; i < n * n; i++) {
        map[i] = temp[i];
    }
}

pair<int, pair<int, int>> bomb() {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n * n; i++) {
        if (map[i] == 0) continue;
        if (map[i] == map[i + 1]) {
            int j = i;
            int b_num = 0;
            while (true) {
                if (j >= n * n) break;
                if (map[i] != map[j]) break;
                b_num++;
                j++;
            }
            if (b_num >= 4) {
                for (int k = 0; k < b_num; k++) {
                    if (map[i + k] == 1) cnt1++;
                    if (map[i + k] == 2) cnt2++;
                    if (map[i + k] == 3) cnt3++;
                    map[i + k] = 0;
                }
            }
            i = j - 1;
        }
    }
    return {cnt1, {cnt2, cnt3}};
}

void change() {
    int temp[2500] = {0,};
    queue<int> q;
    for (int i = 1; i < n * n; i++) {
        if (map[i] != map[i + 1]) {
            q.push(1); // 개수
            q.push(map[i]); // 구슬번호
        } else {
            if (map[i] != 0) {
                int s_cnt = 0;
                int j = i;
                while (true) {
                    if (map[i] != map[j]) break;
                    s_cnt++;
                    j++;
                }
                q.push(s_cnt);
                q.push(map[i]);
                i = j - 1;
            }
        }
    }
    int idx = 1;
    while (!q.empty()) {
        if (idx >= n * n) break;
        temp[idx] = q.front();
        q.pop();
        idx++;
    }
    for (int i = 1; i < n * n; i++) {
        map[i] = temp[i];
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> imap[i][j];
        }
    }
    shark = {(n + 1) / 2, (n + 1) / 2};
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        destroy(i);
        straight();
        move();
        while (true) {
            int c1, c2, c3;
            pair<int, pair<int, int>> res = bomb();
            c1 = res.first;
            c2 = res.second.first;
            c3 = res.second.second;
            sc1 += c1, sc2 += c2, sc3 += c3;
            if (c1 + c2 + c3 == 0) break;
            move();
        }
        change();
        to_map();
    }
    int ans = (1 * sc1) + (2 * sc2) + (3 * sc3);
    cout << ans;
}