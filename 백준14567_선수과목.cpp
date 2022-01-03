#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, cnt, in[1001], ans[1001];
vector<int> v[1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        v[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        cnt++;
        int sz = q.size();
        while (sz--) {
            int next = q.front();
            q.pop();
            ans[next] = cnt;
            for (auto a: v[next]) {
                in[a]--;
                if (in[a] == 0) q.push(a);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}