#include <iostream>
#include <queue>

using namespace std;
int n, m, cnt, ans, par[1001];

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++) par[i] = i;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }
    while (!pq.empty()) {
        int weight = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        x = Find(par[x]);
        y = Find(par[y]);
        if (x != y) { // 연결 X
            par[y] = x;
            cnt++;
            ans += weight;
        }
        if (cnt == n - 1) {
            cout << ans;
            return 0;
        }
    }
}