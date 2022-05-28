#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[51];
queue<pair<string, int>> q;

bool comp(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) if (s1[i] == s2[i]) cnt++;
    if (cnt == s1.size() - 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 123456789;
    bool find = false;
    for (auto & word : words) if (target == word) find = true;
    if (!find) return 0;

    q.push({begin, 0});
    while (!q.empty()) {
        string str = q.front().first;
        int num = q.front().second;
        if (str == target) if (num < answer) answer = num;
        q.pop();
        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            if (comp(str, words[i])) {
                visited[i] = true;
                q.push({words[i], num + 1});
            }
        }
    }
    return answer;
}