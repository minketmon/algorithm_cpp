#include <iostream>
#include <vector>
#include <algorithm>

#define INF 123456789
using namespace std;
int n, dist[51][51];
vector<pair<int, int>> score;
vector<int> ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)dist[i][j] = INF;
        }
    }
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    // 플로이드
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int _max = -1;
        for (int j = 1; j <= n; j++) {
            _max = max(_max, dist[i][j]);
        }
        score.emplace_back(_max, i);
    }
    sort(score.begin(), score.end());
    int _min = score[0].first;
    for (int i = 0; i < n; i++) {
        if (score[i].first == _min) ans.push_back(score[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << score[0].first << " " << ans.size() << "\n";
    for (int a: ans) cout << a << " ";
}