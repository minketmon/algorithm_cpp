#include <iostream>

using namespace std;
int n, arr[12], op[4], order[12], _min, _max;

void dfs(int op[], int idx) {
    if (idx == n - 1) {
        int res = arr[0];
        for (int i = 0; i < idx; i++) {
            if (order[i] == 0) res += arr[i + 1];
            else if (order[i] == 1) res -= arr[i + 1];
            else if (order[i] == 2) res *= arr[i + 1];
            else if (order[i] == 3) res /= arr[i + 1];
        }
        _max = res > _max ? res : _max;
        _min = res < _min ? res : _min;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            order[idx] = i;
            dfs(op, idx + 1);
            op[i]++;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    _min = 987654321, _max = -987654321;
    dfs(op, 0);
    cout << _max << '\n' << _min << '\n';
}