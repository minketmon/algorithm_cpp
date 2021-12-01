#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> v;
vector<string> answer;

void binary_search(int left, int right, string target) {
    if (left > right) return;
    else {
        int mid = (left + right) / 2;
        if (v[mid] == target) answer.push_back(target);
        else if (v[mid] > target) binary_search(left, mid - 1, target);
        else binary_search(mid + 1, right, target);
    }
}

int main() {
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
        binary_search(0, v.size() - 1, s);
    }
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";
}