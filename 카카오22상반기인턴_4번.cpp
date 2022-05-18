#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define N 50002
using namespace std;

bool summit[N], gate[N];
int dist[N];
vector<pair<int, int>> v[50002];

int findMinIntensity(int st) {
    priority_queue<pair<int, int>> pq;
    memset(dist, -1, sizeof(dist));
    dist[st] = 0;
    pq.push({0, -st});
    while (!pq.empty()) {
        int d = -pq.top().first;
        int now = -pq.top().second;
        pq.pop();
        if (dist[now] > d) continue;
        if (gate[now]) {
            return d;
        }
        for (auto u : v[now]) {
            int next = u.first;
            int nd = max(d, u.second);
            if (dist[next] != -1 && dist[next] <= nd) continue;
            if (summit[next]) continue;
            dist[next] = nd;
            pq.push({-nd, -next});
        }
    }
    return -1;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto u : paths) {
        v[u[0]].emplace_back(u[1], u[2]);
        v[u[1]].emplace_back(u[0], u[2]);
    }
    for (int x : summits)
        summit[x] = true;
    for (int x : gates) {
        gate[x] = true;
    }
    sort(summits.begin(), summits.end());
    int md = 100000000, y;
    for (int x : summits) {
        int tmp = findMinIntensity(x);
        if (tmp == -1) continue;
        if (tmp < md) {
            md = tmp;
            y = x;
        }
    }
    vector<int> ans = {y, md};
    return ans;
}