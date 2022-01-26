#include <iostream>
#include <cstring>

using namespace std;
long long dp[10001][16];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            int manager = 1 << (s[i] - 'A');
            for (int j = 0; j < 16; j++) {
                if (i == 0) {
                    if ((1 & j) != 0 && (manager & j) != 0)dp[i][j] = 1;
                } else {
                    if (dp[i - 1][j] > 0) {
                        for (int k = 0; k < 16; k++) {
                            if ((manager & k) != 0 && (j & k) != 0)  {
                                dp[i][k] += dp[i - 1][j];
                                dp[i][k] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 16; i++) {
            ans += dp[s.size() - 1][i];
            ans %= 1000000007;
        }
        cout << '#' << tc << " " << ans << "\n";
    }
}