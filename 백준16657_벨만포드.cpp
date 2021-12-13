#include <iostream>
#include <vector>

#define INF 123456789
using namespace std;

struct Edge {
    int s, e, d;

    Edge(int _s, int _e, int _d) {
        s = _s;
        e = _e;
        d = _d;
    }
};

int n, m;
long long dist[501];
vector<Edge> edge;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> c >> b;
        edge.emplace_back(a, b, c);
    }

    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int start = edge[j].s;
            int weight = edge[j].e;
            int dest = edge[j].d;
            if (dist[start] == INF) continue;
            if (dist[start] + weight < dist[dest]) {
                dist[dest] = (long long)(dist[start]) + weight;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int start = edge[i].s;
        int weight = edge[i].e;
        int dest = edge[i].d;
        if (dist[start] == INF) continue;
        if (dist[start] + weight < dist[dest]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}
