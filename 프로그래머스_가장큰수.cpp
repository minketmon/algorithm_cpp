#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
    string _s1 = s1 + s1 + s1, _s2 = s2 + s2 + s2;
    if (_s1 > _s2) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    for (auto a: numbers) vec.push_back(to_string(a));
    sort(vec.begin(), vec.end(), comp);
    for (auto a: vec) answer += a;
    bool flag = true;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != '0') flag = false;
    }
    if (flag) return "0";
    return answer;
}