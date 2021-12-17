#include <iostream>
#include <vector>
#include <cstring>

#define INF 123456789
using namespace std;

struct SET {
    int s, e, t;

    SET(int _s, int _e, int _t) {
        s = _s;
        e = _e;
        t = _t;
    }
};

int tc, n, m, w, s, e, t, dist[501];
bool ans;
vector<SET> edge;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> tc;
    while (tc--) {
        ans = false;
        edge.clear();
        memset(dist, 0, sizeof(dist));
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            edge.emplace_back(s, e, t);
            edge.emplace_back(e, s, t);
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            edge.emplace_back(s, e, -t);
        }
        dist[1] = 0;
        for (int i = 1; i < n; i++) {
            for (auto & j : edge) {
                int start = j.s;
                int end = j.e;
                int time = j.t;
                if (dist[end] > dist[start] + time) {
                    dist[end] = dist[start] + time;
                }
            }
        }
        for (auto & i : edge) {
            int start = i.s;
            int end = i.e;
            int time = i.t;
            if (dist[end] > dist[start] + time) {
                ans = true;
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}