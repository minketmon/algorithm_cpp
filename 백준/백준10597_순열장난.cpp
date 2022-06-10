#include <iostream>
#include <vector>

using namespace std;
int len, max_value;
string num;
bool visited[51];
vector<int> v;

void dfs(int ind) {
    if (ind == len) {
        for (int i: v) {
            cout << i << " ";
        }
        cout << "\n";
        exit(0);
    }
    string p = "";
    int ptoi = 0;
    for (int i = ind; i <= ind + 1; i++) {
        p += num[i];
        ptoi = stoi(p);

        if (ptoi > max_value) continue;
        if (visited[ptoi]) continue;

        v.push_back(ptoi);
        visited[ptoi] = true;
        dfs(i + 1);
        visited[ptoi] = false;
        v.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> num;
    len = num.size();
    if (len < 10) max_value = len;
    else max_value = (len - 9) / 2 + 9;
    dfs(0);
}