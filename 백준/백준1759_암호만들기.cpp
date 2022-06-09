#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int l, c, selected[16];
vector<char> v;

void dfs(int idx, int cnt) {
    if (cnt == l) {
        int aeiou = 0, other = 0;
        string s;
        for (int i = 0; i < cnt; i++) {
            s += v[selected[i]];
            if(v[selected[i]] == 'a' || v[selected[i]] == 'e' || v[selected[i]] == 'i' || v[selected[i]] == 'o' || v[selected[i]] == 'u') aeiou++;
            else other++;
        }
        if(aeiou < 1 || other < 2) return;
        cout << s << '\n';
        return;
    }

    for (int i = idx; i < c; i++) {
        selected[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
}