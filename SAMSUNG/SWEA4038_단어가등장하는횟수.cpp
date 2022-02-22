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

// 라빈카프 by 을호

#include <iostream>
#include <string>

#define HASH_TABLE_SIZE 1000003
using namespace std;
typedef unsigned long ul;

int test_case, T, ss, bs, ans;
string b, s;

int main(int argc, char **argv) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> b >> s;
        ss = s.size(), bs = b.size(), ans = 0;

        ul idx1 = 0, val1 = 1, key1 = 0, idx2 = 0, val2 = 1, key2 = 0;

        for (int i = 0; i < ss; i++) {
            key1 = (key1 * 2 + s[i]) % HASH_TABLE_SIZE;
            key2 = (key2 * 33 + s[i]) % HASH_TABLE_SIZE;
        }

        for (int i = 0; i < ss; i++) {
            idx1 = (idx1 * 2 + b[i]) % HASH_TABLE_SIZE;
            val1 = (val1 * 2) % HASH_TABLE_SIZE;
            idx2 = (idx2 * 33 + b[i]) % HASH_TABLE_SIZE;
            val2 = (val2 * 33) % HASH_TABLE_SIZE;
        }
        if (idx1 == key1 && idx2 == key2) ans++;

        for (int i = 1; i <= bs - ss; i++) {
            idx1 = (idx1 * 2 + b[i + ss - 1]) % HASH_TABLE_SIZE;
            idx2 = (idx2 * 33 + b[i + ss - 1]) % HASH_TABLE_SIZE;
            ul tmp1 = (val1 * b[i - 1]) % HASH_TABLE_SIZE;
            ul tmp2 = (val2 * b[i - 1]) % HASH_TABLE_SIZE;
            if (idx1 >= tmp1) idx1 -= tmp1;
            else idx1 += HASH_TABLE_SIZE - tmp1;

            if (idx2 >= tmp2) idx2 -= tmp2;
            else idx2 += HASH_TABLE_SIZE - tmp2;

            if (idx1 == key1 && idx2 == key2) ans++;
        }

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}