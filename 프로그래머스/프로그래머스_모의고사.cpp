#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int a[] = {1, 2, 3, 4, 5};
int b[] = {2, 1, 2, 3, 2, 4, 2, 5};
int c[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int a_cnt, b_cnt, c_cnt;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first < p2.first) {
        if (p1.second > p2.second) return false;
        else return true;
    } else {
        if (p1.second < p2.second) return false;
        else return true;
    }
}

vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> answer;
    vector<int> res;
    for (int i = 0; i < answers.size(); i++) {
        if (a[i % 5] == answers[i]) a_cnt++;
        if (b[i % 8] == answers[i]) b_cnt++;
        if (c[i % 10] == answers[i]) c_cnt++;
    }
    answer.push_back({a_cnt, 1});
    answer.push_back({b_cnt, 2});
    answer.push_back({c_cnt, 3});
    sort(answer.begin(), answer.end(), comp);
    if (answer[0].first == answer[1].first && answer[1].first == answer[2].first) {
        res.push_back(1);
        res.push_back(2);
        res.push_back(3);
    } else if (answer[0].first == answer[1].first) {
        if (answer[0].second < answer[1].second) {
            res.push_back(answer[1].second);
            res.push_back(answer[0].second);
        } else {
            res.push_back(answer[0].second);
            res.push_back(answer[1].second);
        }
    } else res.push_back(answer[0].second);
    return res;
}