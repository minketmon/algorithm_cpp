#include <string>
#include <vector>
#include <queue>

#define INF 123456789
using namespace std;
vector<int> v[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (auto a: edge) {
        v[a[0]].push_back(a[1]);
        v[a[1]].push_back(a[0]);
    }
    queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        int cur = q.front().second;
        int weight = q.front().first;
        q.pop();
        for (int next : v[cur]) {
            int total = weight + 1;
            if (dist[next] <= total) continue;
            dist[next] = total;
            q.push({total, next});
        }
    }
    int max = dist[2], cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > max) {
            max = dist[i];
            cnt = 0;
        }
        if (dist[i] == max) cnt++;
    }
    return cnt;
}