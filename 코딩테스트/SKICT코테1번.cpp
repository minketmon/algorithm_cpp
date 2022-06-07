#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int cash[] = {1, 5, 10, 50, 100, 500};


int solution(int money, vector<int> costs) {
    int answer = 0;
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < costs.size(); i++) {
        double d =  (double) costs[i] / (double) cash[i];
        pq.push({-d, i});
    }
    while (money != 0) {
        int now = cash[pq.top().second];
        int temp = money / now;
        money %= now;
        answer += temp * costs[pq.top().second];
        pq.pop();
    }
    return answer;
}

int main() {
    vector<int> v, v2;
    v.push_back(1), v.push_back(4), v.push_back(99), v.push_back(35), v.push_back(50), v.push_back(1000);
    v2.push_back(2), v2.push_back(11), v2.push_back(20), v2.push_back(100), v2.push_back(200), v2.push_back(600);

    cout << solution(1999, v2);
}