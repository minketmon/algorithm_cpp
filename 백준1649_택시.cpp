#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, start, dest, k, in[1001], visited[1001], check[1001];
vector<int> v[1001], pass;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        in[y]++;
    }
    cin >> start >> dest >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        pass.push_back(num);
    }
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto a: v[cur]) {
            int next = a;
            if (in[next] > 0) {
                in[next]--;
                cout << next << " ";
                check[next]++;
            }
            if (in[next] == 0) q.push(next);
        }
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << check[i] << " ";
    }
}