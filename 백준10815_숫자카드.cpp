#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

//int binary_search(int left, int right, int target) {
//    int mid = (left + right) / 2;
//    if (left > right) return 0;
//    else {
//        if (v[mid] == target) return 1;
//        else if (v[mid] > target) { // 타겟이 왼쪽이면
//            return binary_search(left, mid - 1, target);
//        } else { // 타겟이 오른쪽이면
//            return binary_search(mid + 1, right, target);
//        }
//    }
//}

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

    // -10 2 3 6 10
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        int temp = lower_bound(v.begin(), v.end(), num) - v.begin();
        if (v[temp] == num) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}