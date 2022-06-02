#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, visited[101], ans;
vector<int> v[101];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int &i: v[now]) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
            ans++;
        }
    }

    cout << ans;
}
/*
7
6
1 2
2 3
1 5
5 2
5 6
4 7
 */