#include <iostream>
#include <vector>

using namespace std;
int n, dp[1000001], track[1000001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        track[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                track[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                track[i] = i / 3;
            }
        }
    }
    for(int i=2; i<=n; i++) cout << track[i] << ' ';
    cout << '\n';
    int now = n;
    cout << dp[n] << '\n';
    while(true) {
        cout << now << ' ';
        if(now == 1) break;
        now = track[now];
    }
}