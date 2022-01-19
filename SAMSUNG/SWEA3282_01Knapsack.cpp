#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int dp[1001][1001], v[101], c[101];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int n, k;
        memset(dp, 0, sizeof(dp));
        memset(v, 0, sizeof(v)); // 부피
        memset(c, 0, sizeof(c)); // 가치
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> v[i] >> c[i];
        for (int i = 1; i <= n; i++) { // 물건
            for (int j = 1; j <= k; j++) { // 부피
                if (v[i - 1] <= j) {
                    dp[i][j] =
                            c[i - 1] + dp[i - 1][j - v[i - 1]] > dp[i - 1][j] ? c[i - 1] + dp[i - 1][j - v[i - 1]] : dp[
                                    i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << '#' << tc << " " << dp[n][k] << "\n";
    }
    return 0;
}