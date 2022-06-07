#include <iostream>

using namespace std;
bool composite[1000001];

void Eratos() {
    composite[1] = true;
    for (int i = 2; i * i <= 1000001; i++) {
        if (composite[i]) continue;
        for (int j = 2 * i; j <= 1000001; j += i) {
            composite[j] = true;
        }
    }
}

void gold(int n) {
    for (int cur = 3; cur < n; cur++) {
        if (composite[cur]) continue;
        else { // cur가 소수임
            if (!composite[n - cur]) {
                cout << n << " = " << cur << " + " << n - cur << "\n";
                return;
            }
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Eratos();
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        gold(n);
    }
}