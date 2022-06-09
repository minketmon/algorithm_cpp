#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int ans = 987654321;
vector<int> v[101];
bool visited[101];

int nodeCnt(int start, int skip) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next: v[cur]) {
            if (visited[next] || next == skip)continue;
            visited[next] = true;
            q.push(next);
        }
        cnt++;
    }
    return cnt;
}

int solution(int N, vector<vector<int>> wires) {
    for (auto wire: wires) {
        v[wire[0]].push_back(wire[1]);
        v[wire[1]].push_back(wire[0]);
    }
    for (auto &wire: wires) {
        int a = wire[0];
        int b = wire[1];
        int a_cnt = nodeCnt(a, b);
        int b_cnt = nodeCnt(b, a);
        int gap = abs(a_cnt - b_cnt);
        ans = ans < gap ? ans : gap;
    }
    return ans;
}