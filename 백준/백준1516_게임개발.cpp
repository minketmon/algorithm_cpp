#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, t[501], in[501], ans[501];
vector<int> v[501];
priority_queue<pair<int, int>> pq;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        while (true) {
            int pre;
            cin >> pre;
            if (pre == -1) break;
            v[pre].push_back(i);
            in[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) pq.push({-t[i], i});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        ans[cur] = d;
        for (auto a: v[cur])
            if (--in[a] == 0) pq.push({-(d + t[a]), a});
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}