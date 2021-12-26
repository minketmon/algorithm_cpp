#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k, ans;
vector<int> top[5];
pair<int, int> rotation[101];

void play() {
    for (int i = 0; i < k; i++) {
        int num = rotation[i].first;
        int dir = rotation[i].second;
        int need_rotation[] = {0, 0, 0, 0};
        need_rotation[num] = dir;
        if (num == 1) {
            if (top[1][6] != top[0][2]) need_rotation[0] = -dir;
            if (top[1][2] != top[2][6]) {
                need_rotation[2] = -dir;
                if (top[2][2] != top[3][6]) need_rotation[3] = dir;
            }
        } else if (num == 2) {
            if (top[2][2] != top[3][6]) need_rotation[3] = -dir;
            if (top[2][6] != top[1][2]) {
                need_rotation[1] = -dir;
                if (top[1][6] != top[0][2]) need_rotation[0] = dir;
            }
        } else if (num == 0) { // 1번 톱니, 오른쪽 극 확인
            int temp = dir;
            for (int j = 0; j < 3; j++) {
                temp = -temp;
                if (top[j][2] == top[j + 1][6]) break;
                else need_rotation[j + 1] = temp;
            }
        } else { // 4번 톱니, 왼쪽 극 확인
            int temp = dir;
            for (int j = 3; j > 0; j--) {
                temp = -temp;
                if (top[j][6] == top[j - 1][2]) break;
                else need_rotation[j - 1] = temp;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (need_rotation[j] == 1) {
                rotate(top[j].rbegin(), top[j].rbegin() + 1, top[j].rend()); // 시계
            } else if (need_rotation[j] == -1) {
                rotate(top[j].begin(), top[j].begin() + 1, top[j].end()); // 반시계
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (char j : s) {
            top[i].push_back(j - '0');
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        rotation[i] = {num - 1, dir};
    }
    play();
    if (top[0][0] == 1) ans += 1;
    if (top[1][0] == 1) ans += 2;
    if (top[2][0] == 1) ans += 4;
    if (top[3][0] == 1) ans += 8;
    cout << ans;
}