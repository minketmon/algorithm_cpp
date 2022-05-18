#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<char, int> m;
char ans[4];
string solution(vector<string> survey, vector<int> choices) {
    for (int i = 0; i < survey.size(); i++) {
         if(choices[i] == 1) m[survey[i][0]] += 3;
         else if(choices[i] == 2) m[survey[i][0]] += 2;
         else if(choices[i] == 3) m[survey[i][0]] += 1;
         else if(choices[i] == 5) m[survey[i][1]] += 1;
         else if(choices[i] == 6) m[survey[i][1]] += 2;
         else if(choices[i] == 7) m[survey[i][1]] += 3;
    }

    if(m['R'] < m['T']) ans[0] = 'T';
    else ans[0] = 'R';
    if(m['C'] < m['F']) ans[1] = 'F';
    else ans[1] = 'C';
    if(m['J'] < m['M']) ans[2] = 'M';
    else ans[2] = 'J';
    if(m['A'] < m['N'])ans[3] = 'N';
    else ans[3] = 'A';

    cout << ans;
    return ans;
}
int main () {
    m.insert({'R', 0});
    m.insert({'T', 0});
    m.insert({'C', 0});
    m.insert({'F', 0});
    m.insert({'J', 0});
    m.insert({'M', 0});
    m.insert({'A', 0});
    m.insert({'N', 0});

    vector<string> survey;
    vector<int> choices;

    survey.push_back("AN");
    survey.push_back("CF");
    survey.push_back("MJ");
    survey.push_back("RT");
    survey.push_back("NA");

    choices.push_back(5);
    choices.push_back(3);
    choices.push_back(2);
    choices.push_back(7);
    choices.push_back(5);

    solution(survey, choices);
}


/*
 * #include <string>
#include <vector>

using namespace std;

int score[8];
int ctoi[26];
char mbti[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < 8; i++) {
        ctoi[mbti[i] - 'A'] = i;
    }
    int x, y;
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] == 4) continue;
        else if (choices[i] < 4) {
            x = ctoi[survey[i][0] - 'A'];
            y = 4 - choices[i];
        } else {
            x = ctoi[survey[i][1] - 'A'];
            y = choices[i] - 4;
        }
        score[x] += y;
    }

    answer.resize(4);
    if (score[6] < score[7])
        answer[0] = 'T';
    else
        answer[0] = 'R';
    if (score[1] < score[2])
        answer[1] = 'F';
    else
        answer[1] = 'C';
    if (score[3] < score[4])
        answer[2] = 'M';
    else
        answer[2] = 'J';
    if (score[0] < score[5])
        answer[3] = 'N';
    else
        answer[3] = 'A';
    return answer;
}
 */