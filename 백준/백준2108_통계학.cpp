#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
vector<pair<int, int>> vv;
int num;
int cnt[8002];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else return a.first < b.first;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        v.push_back(num);
        if (cnt[num + 4000] == 0) vv.push_back(pair<int, int>(num, 1));
        cnt[num + 4000]++;
    }
    for (int i = 0; i < vv.size(); i++) vv[i].second = cnt[vv[i].first + 4000];

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end(), compare);
    cout.precision(1);
    cout << int(round(sum / n)) << "\n";
    cout << v[n / 2] << "\n";
    if (vv[0].second == vv[1].second) cout << vv[1].first << "\n";
    else cout << vv[0].first << "\n";
    cout << v[n - 1] - v[0];
}