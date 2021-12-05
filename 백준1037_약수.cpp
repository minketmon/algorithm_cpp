#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << v[0] * v[v.size() - 1];
}