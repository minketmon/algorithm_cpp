//#include <iostream>
//#include <queue>
//#include <vector>
//#define INF 123456789
//using namespace std;
//int v, e, k;
//
//vector<pair<int, int>> edge[20001];
//int dist[20001];
//
//int main() {
//    cin.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    cin >> v >> e >> k;
//    for (int i = 0; i < e; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        edge[a].push_back({b, c});
//    }
//    priority_queue<pair<int, int>> pq;
//    for(int i=1; i<=v; i++){
//        dist[i] = INF;
//    }
//    dist[k] = 0;
//    pq.push({0, k});
//    while(!pq.empty()){
//        int weight = -pq.top().first;
//        int vertex = pq.top().second;
//        pq.pop();
//        for(int i=0; i<edge[vertex].size(); i++){
//            int next = edge[vertex][i].first;
//            int total = weight + edge[vertex][i].second;
//            if(dist[next] <= total) continue;
//            dist[next] = total;
//            pq.push({-total, next});
//        }
//    }
//    for(int i=1; i<=v; i++ ){
//        if(dist[i]==INF) cout << "INF\n";
//        else cout << dist[i] << "\n";
//    }
//}

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;
int v, e, k, dist[20001];
vector<pair<int, int>> vec[20001];

int main() {
    cin >> v >> e >> k;
    for (int i = 1; i <= v; i++) dist[i] = INF;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});
    dist[k] = 0;
    while (!pq.empty()) {
        int weight = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int d = weight + vec[cur][i].second;
            if (dist[next] <= d) continue;
            dist[next] = d;
            pq.push({-d, next});
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}