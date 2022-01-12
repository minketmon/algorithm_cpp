#include <iostream>
#include <queue>

using namespace std;
int n, m, cnt, ans, par[10001];

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push({-z, {x, y}});
    }
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = -pq.top().first;
        pq.pop();
        x = Find(x);
        y = Find(y);
        if (x != y) {
            cnt++;
            par[y] = x;
            ans += w;
        }
        if (cnt == n - 1) break;
    }
    cout << ans;
}