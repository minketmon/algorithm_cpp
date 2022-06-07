#include <iostream>
#include <vector>

using namespace std;

bool composite[10001];
vector<int> v;

void Eratos() {
    composite[1] = true;
    for (int i = 2; i * i <= 10000; i++) {
        if (composite[i]) continue;
        for (int j = 2 * i; j <= 10000; j += i) {
            composite[j] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Eratos();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    for (int i = 0; i < t; i++) {
        int cur = v[i] / 2;
        if (!composite[cur]) cout << cur << " " << cur << "\n";
        else {
            while (cur--) {
                if (composite[cur]) continue;
                else { // cur가 소수임
                    if (!composite[v[i] - cur]) {
                        cout << cur << " " << v[i] - cur << "\n";
                        break;
                    }
                }
            }
        }
    }
}