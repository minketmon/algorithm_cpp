#include <string>
#include <vector>
#include <iostream>

using namespace std;
int num_cnt, _max;
vector<char> vec;
bool visited[1000001];

void permutation(int idx, int cnt) {
    if (cnt == num_cnt) {
        string temp;
        for (int i = 0; i < vec.size(); i++) {
            if (visited[i]) temp += vec[i];
        }
        _max = _max < stoi(temp) ? stoi(temp) : _max;
    }
    for (int i = idx; i < vec.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        permutation(i, cnt + 1);
        visited[i] = false;
    }

}

string solution(string number, int k) {
    string answer;
    num_cnt = number.size() - k;
    for (char &i: number) vec.push_back(i);
    permutation(0, 0);
    answer += to_string(_max);
    cout << "ANS : " << answer << '\n';
    return answer;
}

int main() {
    solution("4177252841", 4);
}