#include <iostream>
#include <algorithm>

#define INF 123456789
using namespace std;

int n, m, ans[101], dist[101][101];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF || dist[j][i] != INF)
                ans[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << n - ans[i] << "\n";
    }
}