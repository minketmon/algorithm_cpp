#include <iostream>
#include <cstring>

using namespace std;
int h, w, n, m;
int small[2001][2001], big[2001][2001];


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        char c;
        cin >> h >> w >> n >> m;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                cin >> c;
                if (c == 'o') small[i][j] = 1;
                else small[i][j] = 0;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> c;
                if (c == 'o') big[i][j] = 1;
                else big[i][j] = 0;
            }
        for (int i = 0; i < h; i++) {
            // 해시 존나어렵당.
        }
        cout << '#' << tc << ' ' << '\n';
    }
}