// #1. 다익스트라 (but 사이클 없음)
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n, k, dist[100001], ans;
bool live[100001];
vector<int> v[100001];

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 1; i <= n; i++)v[i].clear();
        cin >> n >> k;
        ans = 0;
        for (int i = 1; i <= n; i++) dist[i] = INF;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) cin >> live[i];
        for (int now = 1; now <= n; now++) {
            for (int i = 1; i <= n; i++) dist[i] = INF;
            priority_queue<pair<int, int> > pq;
            dist[now] = 0;
            pq.push({ 0, now });
            while (!pq.empty()) {
                int cur = pq.top().second;
                int d = -pq.top().first;
                pq.pop();
                for (int next : v[cur]) {
                    int nd = d + 1;
                    if (dist[next] <= nd) continue;
                    dist[next] = nd;
                    pq.push({ -nd, next });
                }
            }
            for (int i = 1; i <= n; i++) {
                if (dist[i] <= k && live[i]) ans++;
            }
        }
        cout << "#" << tc << ' ' << ans << '\n';
    }
}

// #2. DFS
#include <iostream>
#include <vector>

using namespace std;
int n, k, ans;
bool live[100001], visited[100001], res[100001];
vector<int> v[100001];

void dfs(int idx, int cnt) {
    if (cnt <= k) res[idx] = true;
    for (int next: v[idx]) {
        if (visited[next]) continue;
        visited[next] = true;
        dfs(next, cnt + 1);
    }
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 1; i <= n; i++) v[i].clear();
        ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) cin >> live[i];
        for (int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited));
            memset(res, 0, sizeof(res));
            visited[i] = true;
            dfs(i, 0);
            for (int j = 1; j <= n; j++) if (res[j] && live[j]) ans++;
        }
        cout << '#' << tc << ' ' << ans;
    }
}

/* sample input
2
8 1
1 4
5 4
7 5
5 8
3 7
6 5
2 6
1 0 0 1 1 0 0 1
5 6
1 2
2 3
3 4
4 5
1 0 1 1 0

*/