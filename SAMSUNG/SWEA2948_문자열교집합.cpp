#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int n, m, ans = 0;
        unordered_map<string, char> mm;
        string s1, s2;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> s1;
            mm.insert({s1, NULL});
        }
        for (int i = 0; i < m; i++) {
            cin >> s2;
            ans = mm.count(s2) > 0 ? ++ans : ans;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}