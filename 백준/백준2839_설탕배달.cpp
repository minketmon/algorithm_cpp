#include <iostream>

using namespace std;
int n, dp[50001], ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    dp[3] = 1, dp[5] = 1;
    for (int i = 6; i <= n; i++) {
        bool flag = false;
        if (dp[i - 3]) {
            flag = true;
            dp[i] = dp[i - 3] + 1;
        }
        if (dp[i - 5]) {
            if (flag) dp[i] = dp[i] < dp[i - 5] + 1 ? dp[i] : dp[i - 5] + 1;
            else dp[i] = dp[i - 5] + 1;
        }
    }
    ans = dp[n] == 0 ? -1 : dp[n];
    cout << ans;
}