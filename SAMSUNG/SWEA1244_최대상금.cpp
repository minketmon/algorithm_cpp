#include <iostream>
#include <cstdio>

using namespace std;
string s, c_str, ans;
int change, change2;

void dfs(int idx, int cnt) {
    if (cnt == change) {
        change2 = change;
        c_str = c_str < s ? s : c_str;
        return;
    }
    for (int i = idx; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] <= s[j]) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                dfs(i, cnt + 1);
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        change2 = 0;
        cin >> s >> change;
        c_str = s;
        dfs(0, 0);
        int remain = change - change2;
        if (remain % 2 == 1) {
            int sz = s.length();
            char temp = s[sz - 2];
            s[sz - 2] = s[sz - 1];
            s[sz - 1] = temp;
            ans = s;
        } else ans = c_str;
        cout << '#' << test_case << " " << ans << "\n";
    }
    return 0;
}