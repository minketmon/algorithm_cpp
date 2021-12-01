#include <iostream>

using namespace std;
int composite[1000000];

int main() {
    int m, n;
    cin >> m >> n;

    composite[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (composite[i]) continue;
        for (int j = 2 * i; j <= n; j += i)
            composite[j] = true;
    }
    for (int i = m; i <= n; i++)
        if (!composite[i]) cout << i << "\n";
}
