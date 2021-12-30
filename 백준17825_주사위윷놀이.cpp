#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int score[35], ans, mal[5];
int soonseo[11];
vector<int> v[35];

void init() {
    for (int i = 0; i <= 20; i++) {
        v[i].push_back(i + 1);
    }
    v[21].push_back(21);
    v[5].push_back(22);
    v[22].push_back(23);
    v[23].push_back(24);
    v[24].push_back(25);
    v[25].push_back(26);
    v[26].push_back(27);
    v[27].push_back(20);
    v[10].push_back(31);
    v[31].push_back(32);
    v[32].push_back(25);
    v[15].push_back(28);
    v[28].push_back(29);
    v[29].push_back(30);
    v[30].push_back(25);
    for (int i = 1; i <= 20; i++) {
        score[i] = i * 2;
    }
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[31] = 22;
    score[32] = 24;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
}

void dfs(int cnt, int sc) {
    if (cnt == 10) {
        ans = max(ans, sc);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int location = mal[i];
        int move = soonseo[cnt];
        int next = location;
        if (v[next].size() > 1) {
            next = v[next][1];
            move--;
        }
        for (int j = 0; j < move; j++) {
            next = v[next][0];
        }
        bool flag = false;
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                if (next != 21 && mal[j] == next) flag = true;
            }
        }
        if (flag) continue;
        mal[i] = next;
        dfs(cnt + 1, sc + score[next]);
        mal[i] = location;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 10; i++) cin >> soonseo[i];
    init();
    dfs(0, 0);
    cout << ans;
}