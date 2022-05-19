#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer, temp;
    int cnt = 0, z_cnt = 0;
    for (int lotto : lottos) {
        if (lotto == 0) z_cnt++;
        for (int win_num : win_nums) {
            if (lotto == win_num) cnt++;
        }
    }
    int high = cnt + z_cnt;
    int low = cnt;
    if (high >= 6) answer.push_back(1);
    else if (high == 5) answer.push_back(2);
    else if (high == 4) answer.push_back(3);
    else if (high == 3) answer.push_back(4);
    else if (high == 2) answer.push_back(5);
    else if (high <= 1) answer.push_back(6);

    if (low >= 6) answer.push_back(1);
    else if (low == 5) answer.push_back(2);
    else if (low == 4) answer.push_back(3);
    else if (low == 3) answer.push_back(4);
    else if (low == 2) answer.push_back(5);
    else if (low <= 1) answer.push_back(6);

    return answer;
}