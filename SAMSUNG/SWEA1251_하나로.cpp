#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

long long n, ans, par[1001];
double e;
pair<long long, long long> p[1001];
vector<pair<long long, pair<long long, long long>>> edge;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cout << fixed;
    cout.precision(0);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        memset(par, 0, sizeof(par));
        edge.clear();
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) par[i] = i;
        long long a;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            p[i].first = a;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a;
            p[i].second = a;
        }
        cin >> e;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                long long dx = (p[i].first - p[j].first) * (p[i].first - p[j].first);
                long long dy = (p[i].second - p[j].second) * (p[i].second - p[j].second);
                edge.push_back({dx + dy, {i, j}});
            }
        }
        sort(edge.begin(), edge.end());
        for (auto &i: edge) {
            long long x = Find(i.second.first), y = Find(i.second.second);
            if (x != y) {
                par[y] = x;
                ans += i.first;
            }
        }
        cout << "#" << tc << " " << (double) (e * ans) << endl;
    }
}