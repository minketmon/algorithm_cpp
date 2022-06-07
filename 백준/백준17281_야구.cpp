#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int map[51][10], n, order[50], ans, soons[10], score;
bool visited[10];
vector<int> v;

void play() {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int out_cnt = 0;
        bool ru[4] = {false, false, false, false}; // 홈 1 2 3
        //안타: 1, 2루타: 2, 3루타: 3, 홈런: 4, 아웃: 0
        while (true) {
            ru[0] = true;
            if (j > 8) j = 0;
            int res = map[i][soons[j]];
            if (res == 0) {
                out_cnt++; // 아웃
                if (out_cnt == 3) {
                    j = j + 1;
                    break;
                }
            } else if (res == 1) { // 안타
                for (int k = 3; k >= 0; k--) {
                    if (k == 3) {
                        if (ru[k]) {
                            score++, ru[k] = false;
                            continue;
                        }
                    }
                    else ru[k + 1] = ru[k], ru[k] = false;
                }
            } else if (res == 2) { // 2루타
                for (int k = 3; k >= 0; k--) {
                    if (k == 3 || k == 2) {
                        if (ru[k]) {
                            score++, ru[k] = false;
                            continue;
                        }
                    }
                    else ru[k + 2] = ru[k], ru[k] = false;
                }
            } else if (res == 3) { // 3루타
                for(int k=3; k>=0; k--){
                    if(k!=0){
                        if(ru[k]){
                            score++, ru[k] = false;
                            continue;
                        }
                    }
                    else ru[k+3] = ru[k], ru[k] = false;
                }
            } else if (res == 4) { // 홈런
                for (int k = 3; k >= 0; k--) {
                    if(ru[k]) score++, ru[k] = false;
                }
            }
            j++;
        }
    }
}

void permutation(int now) {
    if (now == 8) {
        memset(soons, 0, sizeof(soons));
        for (int i = 0; i < 9; i++) {
            if (i == 3) soons[i] = 1;
            if (i > 2) soons[i + 1] = v[order[i]];
            else
                soons[i] = v[order[i]];
        }
        score = 0;
        play();
        ans = max(ans, score);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        order[now] = i;
        permutation(now + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (i == 1) continue;
        v.push_back(i);
    }
    permutation(0);
    cout << ans;
}