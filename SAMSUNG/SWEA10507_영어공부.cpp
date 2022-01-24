#include <iostream>
#include <cstring>

using namespace std;
int n, chance, ans, study[200001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        ans = 0;
        memset(study, 0, sizeof(study));
        cin >> n >> chance;
        for (int i = 0; i < n; i++) cin >> study[i];
        int start = 0, end = 0;
        while (end < n) {
            int len = study[end] - study[start] - end + start;
            int cmp = chance - start + end + 1;
            if (len > chance) start++;
            else {
                ans = ans < cmp ? cmp : ans;
                end++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}