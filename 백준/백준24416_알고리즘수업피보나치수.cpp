#include <iostream>

using namespace std;
int n, f[10000], cnt;

int fibonacci(int n) {
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2], cnt++;
    return f[n];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    fibonacci(n);
    cout << f[n] << ' ' << cnt;
}