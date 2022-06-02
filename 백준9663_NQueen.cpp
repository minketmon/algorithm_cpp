#include <iostream>

using namespace std;
int n, ans, arr[20];

bool check(int x) {
    for (int i = 0; i < x; i++) if (arr[i] == arr[x] || abs(arr[i] - arr[x]) == abs(i - x)) return false;
    return true;
}

void dfs(int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[cnt] = i;
        if (check(cnt)) dfs(cnt + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(0);
    cout << ans;
}