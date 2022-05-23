#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool findBigger(queue<pair<int, int>> q) {
    int top = q.front().first;
    while (!q.empty()) {
        int temp = q.front().first;
        q.pop();
        if (top < temp) return true;
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0, cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) q.push({priorities[i], i});
    while (!q.empty()) {
        if (findBigger(q)) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            q.push({a, b});
        } else {
            if (q.front().second == location) return ++cnt;
            q.pop();
            cnt++;
        }
    }
    return cnt;
}