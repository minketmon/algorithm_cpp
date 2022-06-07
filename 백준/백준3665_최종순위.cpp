#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int tc, n, m, ranking[501];

void sol() {
    bool cycle = false;
    vector<int> v[501];
    memset(ranking, 0, sizeof(ranking));
    cin >> n;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        ranking[i] = num;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            v[ranking[i]].push_back(ranking[j]);
    }
    cin >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        bool flag = false;
        for (auto &x: v[a]) {
            if (x == b) {
                flag = true; // 발견
                x = 0;
                v[b].push_back(a);
            }
        }
        if (!flag) {
            v[a].push_back(b);
            for (auto &x: v[b]) {
                if (x == a) {
                    x = 0;
                }
            }
        }
    }
    vector<pair<int, int>> cnt;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (auto a: v[i]) {
            if (a != 0) c++;
        }
        cnt.push_back({c, i});
    }
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < n - 1; i++) {
        if (cnt[i].first == cnt[i + 1].first) {
            cycle = true;
        }
    }
    if (cycle) cout << "IMPOSSIBLE\n";
    else {
        for (int i = n - 1; i >= 0; i--)
            cout << cnt[i].second << " ";
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> tc;
    while (tc--)
        sol();
}
