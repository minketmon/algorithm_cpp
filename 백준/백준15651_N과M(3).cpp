#include <iostream>

using namespace std;
int n, m, arr[10];

void sol(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[cnt] = i;
        sol(cnt + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    sol(0);
}