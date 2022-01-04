#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, in[32001];
vector<int> v[32001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 0)q.push(-i);
    while (!q.empty()) {
        int cur = -q.top();
        cout << cur << " ";
        q.pop();
        for (auto a: v[cur]) {
            if (--in[a] == 0) q.push(-a);
        }
    }
}