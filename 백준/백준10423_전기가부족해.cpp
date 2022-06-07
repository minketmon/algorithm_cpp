#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, k, par[1001], cnt, ans;
bool power[1001];

int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) par[i] = i;
    int p;
    while (k--) {
        cin >> p;
        power[p] = true;
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        pq.push({-w, {u, v}});
    }
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int weight = -pq.top().first;
        pq.pop();
        x = Find(x);
        y = Find(y);
        if (power[x] && power[y]) continue;
        if (x != y) {
            if (power[y]) par[x] = y;
            else par[y] = x;
            cnt++;
            ans += weight;
        }
    }
    cout << ans;
}
