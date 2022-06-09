#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> min, max;
    int cnt = 0;
    for (string s: operations) {
        int num = stoi(s.substr(2));
        if (s[0] == 'I') { // insert
            min.push(-num);
            max.push(num);
            cnt++;
        } else { // delete
            if (cnt == 0) continue;
            if (num == 1) max.pop();
            else min.pop();
            cnt -= 1;
        }
    }
    if (cnt == 0) return {0, 0};
    return {max.top(), -min.top()};
}