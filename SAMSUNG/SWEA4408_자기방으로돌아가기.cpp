#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int T, test_case;
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        int n, a, b, x, y, road[201] = {0,};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (a < b) {
                if (a % 2 == 1) x = a / 2;
                else x = a / 2 - 1;
                if (b % 2 == 1) y = b / 2;
                else y = b / 2 - 1;
            } else {
                if (b % 2 == 1) x = b / 2;
                else x = b / 2 - 1;
                if (a % 2 == 1) y = a / 2;
                else y = a / 2 - 1;
            }
            for (int i = x; i <= y; i++) road[i]++;
        }
        int _max = -1;
        for (int i = 0; i < 200; i++) {
            _max = _max < road[i] ? road[i] : _max;
        }
        cout << '#' << test_case << " " << _max << "\n";
    }
    return 0;
}