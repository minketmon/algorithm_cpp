#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T, test_case;
    int cash[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    cin >> T;
    for (test_case = 1; test_case <= T; test_case++) {
        int n, cnt[9] = {0,};
        cin >> n;
        for(int i=0; i<8; i++){
            if(n >= cash[i]) {
                cnt[i] += n/cash[i];
                n %= cash[i];
            }
        }
        cout << '#' << test_case << "\n";
        for(int i=0; i<8; i++) cout << cnt[i] << " ";
        cout << "\n";
    }
    return 0;
}