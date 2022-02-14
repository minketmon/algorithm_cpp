#include <iostream>
#include <cstring>

using namespace std;
int pi[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        memset(pi, 0, sizeof(pi));
        int ans = 0;
        string s1, s2;
        cin >> s1 >> s2;
        int s1_len = s1.length(), s2_len = s2.length(), j = 0;
        for (int i = 1; i < s2_len; i++) {
            while (j > 0 && s2[i] != s2[j])
                j = pi[j - 1];
            if (s2[i] == s2[j]) pi[i] = ++j;
        }
        j = 0;
        for (int i = 0; i < s1_len; i++) {
            while (j > 0 && s1[i] != s2[j]) j = pi[j - 1];
            if (s1[i] == s2[j]) {
                if (j == s2_len - 1) {
                    ans++;
                    j = pi[j];
                } else j++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}