#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
queue<pair<int, int>> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0, idx = 0, time = 0;
    q.push({truck_weights[idx], time++});
    sum += truck_weights[idx];
    while(true) {
        if(q.empty()) break;
        if(idx+1 == truck_weights.size()) {
            if(time - q.front().second >= bridge_length) {
                sum -= q.front().first;
                q.pop();
            } else time++;
            continue;
        }
        if(time - q.front().second >= bridge_length) {
            sum -= q.front().first;
            q.pop();
        }
        if(sum + truck_weights[idx+1] <= weight) {
            q.push({truck_weights[++idx], time});
            sum += truck_weights[idx];
        }
        time++;
    }
    return ++time;
}