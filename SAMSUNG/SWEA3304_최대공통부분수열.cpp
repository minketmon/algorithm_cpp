#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int lcs[1001][1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int ans = -1;
        memset(lcs, 0, sizeof(lcs));
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1[i - 1] == s2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
                ans = lcs[i][j] > ans ? lcs[i][j] : ans;
            }
        }
        cout << '#' << tc << " " << ans << "\n";
    }
}