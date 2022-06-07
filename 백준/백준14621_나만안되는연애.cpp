#include <iostream>
#include <queue>

using namespace std;
int n, m, ans, cnt, par[1001];
char gender[1001];

int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) cin >> gender[i];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (gender[x] != gender[y]) {
            pq.push({-z, {x, y}});
        }
    }
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int weight = -pq.top().first;
        pq.pop();
        x = Find(x);
        y = Find(y);
        if (x != y) {
            par[y] = x;
            cnt++;
            ans += weight;
        }
        if (cnt == n - 1) {
            cout << ans;
            return 0;
        }
    }
    cout << -1;
}