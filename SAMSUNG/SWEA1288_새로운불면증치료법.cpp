#include<iostream>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int n, ans = 0, temp = 0;
        cin >> n;
        while (true) {
            ans += n;
            int num = ans;
            while (num > 0) {
                temp |= 1 << (num % 10);
                num /= 10;
            }
            if (temp == 1023) break;
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}