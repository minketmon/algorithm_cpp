#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<pair<int, int>> v[101];
int n, m, in[101], ans[101];
bool not_basic[101];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> k;
        in[y]++;
        not_basic[x] = true;
        v[x].push_back({y, k});
    }
    queue<int> q;
    ans[n] = 1;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto a: v[cur]) {
            int next = a.first;
            int cnt = a.second;
            in[next]--;
            if (in[next] == 0) {
                q.push(next);
            }
            ans[next] += cnt * ans[cur];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!not_basic[i]) cout << i << " " << ans[i] << "\n";
    }
}