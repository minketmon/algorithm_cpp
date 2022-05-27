#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[201];
bool visited[201];
queue<int> q;

void bfs(int num) {
    q.push(num);
    visited[num] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int & i : v[now]) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (i == j) continue;
            if (computers[i][j] == 1) v[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        bfs(i);
        answer++;
    }
    return answer;
}