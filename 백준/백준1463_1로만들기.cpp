#include <iostream>

using namespace std;
int n, dp[1000001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = dp[i / 2] + 1 > dp[i] ? dp[i] : dp[i / 2] + 1;
        if (i % 3 == 0) dp[i] = dp[i / 3] + 1 > dp[i] ? dp[i] : dp[i / 3] + 1;
    }
    cout << dp[n];
}