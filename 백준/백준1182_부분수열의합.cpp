#include <iostream>

using namespace std;
int n, s, arr[21], ans;

void dfs(int idx, int sum, int cnt) {
    if (idx == n) {
        if (sum == s && cnt != 0) ans++;
        return;
    }
    sum += arr[idx];
    dfs(idx + 1, sum, cnt + 1);
    sum -= arr[idx];
    dfs(idx + 1, sum, cnt);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    dfs(0, 0, 0);
    cout << ans;
}