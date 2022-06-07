#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> v;

void sol(int num) {
    if (num == m) {
        int temp = v[0];
        if (v.size() != 1) {
            for (int i = 1; i < v.size(); i++) {
                if (v[i] <= temp) return;
                temp = v[i];
            }
        }
        for (auto x: v) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        sol(num + 1);
        v.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    sol(0);
}
