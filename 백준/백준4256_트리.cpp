#include <iostream>
#include <vector>

using namespace std;
int tc, n;
vector<int> pre, in, ans;

void sol(int left, int right, int root) {
    for (int i = left; i < right; i++) {
        if (pre[root] == in[i]) {
            sol(left, i, root + 1); // 왼
            sol(i + 1, right, i - left + root + 1); // 오
            ans.push_back(pre[root]);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> tc;
    while (tc--) {
        pre.clear(), in.clear(), ans.clear();
        cin >> n;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            pre.push_back(num);
        }
        for (int i = 0; i < n; i++) {
            cin >> num;
            in.push_back(num);
        }
        sol(0, n, 0);
        for (auto a: ans) cout << a << " ";
        cout << "\n";
    }
}