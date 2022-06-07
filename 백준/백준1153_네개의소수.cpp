#include <iostream>
#include <vector>

using namespace std;
int composite[1000001];
vector<int> v;

void Eratos() {
    composite[1] = true;
    for (int i = 2; i * i <= 1000000; i++) {
        if (composite[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i) {
            composite[j] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Eratos();
    int n;
    cin >> n;
    int temp = n;
    int cur = 0;
    if (n < 8) cout << -1;
    else {
        if (n % 2 == 0) { // 짝수
            v.push_back(2);
            v.push_back(2);
            temp = n - 4;
        } else { // 홀수
            v.push_back(2);
            v.push_back(3);
            temp = n - 5;
        }
        cur = temp / 2;
        if (!composite[cur]) {
            v.push_back(cur);
            v.push_back(cur);
        } else {
            while (cur--) {
                if (composite[cur]) continue;
                else { // cur가 소수임
                    if (!composite[temp - cur]) {
                        v.push_back(cur);
                        v.push_back(temp - cur);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) cout << v[i] << " ";
    }
}