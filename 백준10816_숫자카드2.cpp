#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int arr[5000001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        int lower = lower_bound(v.begin(), v.end(), num) - v.begin();
        int upper = upper_bound(v.begin(), v.end(), num) - v.begin();
        cout << upper-lower << " ";
    }
}