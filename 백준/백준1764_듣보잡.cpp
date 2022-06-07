#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> v;
vector<string> answer;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        cin >> s;

        int temp = lower_bound(v.begin(), v.end(), s) - v.begin();
        if(v[temp] == s) {
            answer.push_back(s);
        }
    }
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";
}