#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int used[10001], idx;
vector<vector<string>> temp;

void dfs(int cnt, string now, vector<vector<string>> tickets) {
    if (cnt == tickets.size()) { // 모든 티켓 소진
        vector<pair<int, int>> vec;
        vector<string> t;
        for (int i = 0; i < tickets.size(); i++) vec.push_back({used[i], i});
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() - 1; i++) if (tickets[vec[i].second][1] != tickets[vec[i + 1].second][0]) return;
        t.push_back("ICN");
        for (int i = 0; i < vec.size() - 1; i++) t.push_back(tickets[vec[i].second][1]);
        t.push_back(tickets[vec[vec.size() - 1].second][1]);
        temp.push_back(t);
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (used[i]) continue;
        if (tickets[i][0] == now) {
            used[i] = idx++;
            dfs(cnt + 1, tickets[i][1], tickets);
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    dfs(0, "ICN", tickets);
    sort(temp.begin(), temp.end());
    return temp[0];
}