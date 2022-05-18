#include <vector>

using namespace std;
int cnt;

void dfs(int idx, vector<int> num, int target) {
    if (idx == num.size()) {
        int sum = 0;
        for (int i : num) {
            sum += i;
        }
        if (sum == target) cnt++;
        return;
    }
    dfs(idx + 1, num, target);
    num[idx] *= -1;
    dfs(idx + 1, num, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, numbers, target);
    return cnt;
}