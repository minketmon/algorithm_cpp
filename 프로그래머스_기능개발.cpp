#include <string>
#include <vector>
#include <iostream>

using namespace std;
int day[101];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i = 0; i < progresses.size(); i++) {
        int temp = progresses[i], cnt = 0;
        while (true) {
            if (temp >= 100) break;
            temp += speeds[i];
            cnt++;
        }
        day[i] = cnt;
    }
    int cnt = 1, i = 0, temp = day[0];
    bool flag = false;
    while (true) {
        if (i + 1 == progresses.size()) {
            answer.push_back(cnt);
            break;
        }
        if (temp < day[i + 1]) {
            answer.push_back(cnt);
            cnt = 1;
            flag = false;
            temp = day[i + 1];
        } else {
            if (!flag)temp = day[i];
            cnt++;
            flag = true;
        }
        i++;
    }
    return answer;
}