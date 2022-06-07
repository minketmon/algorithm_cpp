#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> temp;
    map<string, string> m;
    for (int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        string stringBuffer;
        vector<string> x;
        while (getline(ss, stringBuffer, ' ')) x.push_back(stringBuffer);
        if (x[0] == "Enter") {
            if (m.find(x[1]) != m.end()) m[x[1]] = x[2];
            else m.insert({x[1], x[2]});
            temp.push_back({x[1], "님이 들어왔습니다."});
        } else if (x[0] == "Change") m[x[1]] = x[2];
        else temp.push_back({x[1], "님이 나갔습니다."});
    }
    for (auto a: temp) answer.push_back(m[a.first] + a.second);
    return answer;
}