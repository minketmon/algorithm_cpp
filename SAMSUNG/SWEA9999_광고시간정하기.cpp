#include <iostream>
#include <cstring>

using namespace std;
int s[100001], e[100001], cnt[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        memset(s, 0, sizeof(s));
        memset(e, 0, sizeof(e));
        memset(cnt, 0, sizeof(cnt));
        int n, l, start = 0, end = 0, _max = 0;
        cin >> l >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i] >> e[i];
            cnt[i + 1] = cnt[i] + (e[i] - s[i]);
        }
        while (start <= end) {
            if (end >= n) break;
            while (e[end] > s[start] + l) {
                if (s[start] - s[end] + l > 0) {
                    int comp = s[start] - s[end] + l + cnt[end] - cnt[start];
                    _max = _max < comp ? comp : _max;
                } else
                    _max = _max < cnt[end] - cnt[start] ? cnt[end] - cnt[start] : _max;
                start++;
            }
            end++;
        }
        _max = _max < cnt[n] - cnt[start] ? cnt[n] - cnt[start] : _max;
        cout << '#' << tc << " " << _max << "\n";
    }
}