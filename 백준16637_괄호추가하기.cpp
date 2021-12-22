#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<char> oper, oper1;
vector<int> num, num1;
bool visited[22];
string s;
int c, _max = INT_MIN, ans;

int calculate(int a, char op, int b) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else return a * b;
}

void dfs(int idx, int cnt, int k) {
    if (cnt == k) {
        c = 0;
        for (int i = 0; i < oper.size(); i++) {
            if (visited[i]) {
                int t = calculate(num[i], oper[i], num[i + 1]);
                num1[i - c] = t;
                num1.erase(num1.begin() + i + 1 - c);
                oper1.erase(oper1.begin() + i - c);;
                c++;
            }
        }
        ans = num1[0];
        for (int i = 0; i < oper1.size(); i++) {
            ans = calculate(ans, oper1[i], num1[i + 1]);
        }
        _max = max(_max, ans);
        oper1 = oper;
        num1 = num;
    }
    for (int i = idx; i < oper.size(); i++) {
        if (visited[i]) continue;
        if (visited[i - 1] || visited[i + 1]) continue;
        visited[i] = true;
        dfs(i, cnt + 1, k);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t >> s;
    if (t == 1) {
        cout << s;
        return 0;
    }
    for (int i = 0; i < t; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') oper.push_back(s[i]);
        else num.push_back(s[i] - '0');
    }
    int max = (oper.size() + 1) / 2;
    for (int i = max; i > 0; i--) {
        oper1 = oper;
        num1 = num;
        dfs(0, 0, i);
    }
    cout << _max;
}