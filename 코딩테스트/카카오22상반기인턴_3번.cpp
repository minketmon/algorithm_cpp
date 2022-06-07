#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dp[1002][1002];

//problem : 필요 알고력, 필요 코딩력, 증가 알고력, 증가 코딩력, 시간
int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0, n = problems.size();
    for (int i = 0; i < n; i++) {
        if (max_alp < problems[i][0]) {
            max_alp = problems[i][0];
        }
        if (max_cop < problems[i][1]) {
            max_cop = problems[i][1];
        }
    }

    problems.push_back({0, 0, 1, 0, 1});
    problems.push_back({0, 0, 0, 1, 1});
    n += 2;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= alp; i++) {
        for (int j = 0; j <= cop; j++) {
            dp[i][j] = 0;
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {alp, cop}});
    while (!pq.empty()) {
        int d = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        if (dp[i][j] < d) continue;
        if (i >= max_alp && j >= max_cop)
            return d;
        for (int k = 0; k < n; k++) {
            if (problems[k][0] > i || problems[k][1] > j) continue;
            int x = dp[i + problems[k][2]][j + problems[k][3]];
            int nd = d + problems[k][4];
            if (x != -1 && x <= nd) {
                continue;
            }
            dp[i + problems[k][2]][j + problems[k][3]] = nd;
            pq.push({-nd, {i + problems[k][2], j + problems[k][3]}});
        }
    }
}