#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> p;
    for(int i=0; i<record.size(); i++) {
        if(record[i][0]=='E') {
            int j;
            string id, nickname;
            for(j=6; record[i][j] != ' '; j++) {
                id+=record[i][j];
            }
            for(int k=j+1; k<record[i].size(); k++) {
                nickname+=record[i][k];
            }
            m[id] = nickname;
            p.push_back({"E", id});
        }
        else if(record[i][0]=='L') {
            int j;
            string id;
            for(j = 6; j<record[i].size(); j++) {
                id+=record[i][j];
            }
            p.push_back({"L", id});
        }
        else if(record[i][0]=='C') {
            int j;
            string id, nickname;
            for(j = 7; record[i][j]!=' '; j++) {
                id+=record[i][j];
            }
            for(int k = j+1; k<record[i].size(); k++) {
                nickname+=record[i][k];
            }
            m[id] = nickname;
        }
    }

    for(int i=0; i<p.size(); i++) {
        string res;
        res += m[p[i].second];
        if(p[i].first=="E") {
            res+="님이 들어왔습니다.";
        }
        else if(p[i].first=="L") {
            res+="님이 나갔습니다.";
        }
        answer.push_back(res);
    }
    return answer;
}