#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
int n, m, par[101], cnt;
float ans;
vector<pair<float, float>> star;
priority_queue<pair<float, pair<int, int>>> pq;

int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
        float x, y;
        cin >> x >> y;
        star.emplace_back(x, y);
    }
    for (int i = 0; i < star.size(); i++) {
        for (int j = 0; j < star.size(); j++) {
            if (i < j) {
                float _x = star[i].first - star[j].first;
                float _y = star[i].second - star[j].second;
                float dist = sqrt(_x * _x + _y * _y);
                pq.push({-dist, {i, j}});
            }
        }
    }
    while (!pq.empty()) {
        int v = pq.top().second.first;
        int u = pq.top().second.second;
        float weight = -pq.top().first;
        pq.pop();
        int x = Find(v);
        int y = Find(u);
        if (x != y) { // 노연결
            par[y] = x;
            cnt++;
            ans += weight;
        }
        if (cnt == n - 1) {
            cout << fixed << setprecision(2) << ans;
            break;
        }
    }
}