#include <string>
#include <vector>
#include <queue>

using namespace std;

bool findBigger(queue<pair<int, int>> q) {
    int top = q.front().first;
    while (!q.empty()) {
        if (top < q.front().first) return true;
        q.pop();
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) q.push({priorities[i], i});
    while (!q.empty()) {
        if (findBigger(q)) {
            q.push({q.front().first, q.front().second});
            q.pop();
        } else {
            if (q.front().second == location) return ++cnt;
            q.pop();
            cnt++;
        }
    }
    return cnt;
}