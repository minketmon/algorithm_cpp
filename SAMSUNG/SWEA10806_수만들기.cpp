#include <iostream>
#include <queue>

using namespace std;
int n, k, a[11];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        while (pq.top().second) {
            int cnt = -pq.top().first;
            int cur = pq.top().second;
            for (int i = 0; i < n; i++) pq.push({-(cnt + cur % a[i]), cur / a[i]});
            pq.push({-(cnt + cur), 0});
            pq.pop();
        }
        cout << '#' << tc << ' ' << -(pq.top().first) << '\n';
    }
}