#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, in[32001];
vector<int> v[32001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (auto a: v[cur]) if (--in[a] == 0) q.push(a);
    }
}