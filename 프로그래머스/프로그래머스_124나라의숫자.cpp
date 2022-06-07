#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<char> res;

string solution(int n) {
    string answer = "";
    while (n) {
        if (n % 3 == 1) answer += "1";
        else if (n % 3 == 2) answer += "2";
        else if (n % 3 == 0) n -= 1, answer += "4";
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
    return answer;
}