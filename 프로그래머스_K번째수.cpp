#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto & command : commands) {
        vector<int> v;
        for (int j = command[0] - 1; j < command[1]; j++)
            v.push_back(array[j]);
        sort(v.begin(), v.end());
        answer.push_back(v[command[2] - 1]);
    }
    return answer;
}