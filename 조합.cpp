#include <iostream>
#include <vector>

using namespace std;
vector<int> sol, v;
int n, k;
void combination(int idx, int cnt) {
    if (cnt == k) {

        cout << "\n";

    }
    if (idx == n) return;
    sol.push_back(v[idx]);
    combination(idx + 1, cnt + 1);
    sol.pop_back();
    combination(idx + 1, cnt);
}

int main() {
    cin >> n  >> k;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    combination(n, k);
}