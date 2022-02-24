#include <iostream>
#include <queue>

using namespace std;
int n, m, par[50001], ans;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t, s, e, c;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        ans = 0;
        memset(par, 0, sizeof(par));
        priority_queue<pair<int, pair<int, int>>> pq;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) par[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> c;
            pq.push({-c, {s, e}});
        }
        while (!pq.empty()) {
            int start = pq.top().second.first;
            int end = pq.top().second.second;
            int weight = -pq.top().first;
            pq.pop();
            int x = Find(start);
            int y = Find(end);
            if (x != y) {
                if (x < y) par[y] = x;
                else par[x] = y;
                ans += weight;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}