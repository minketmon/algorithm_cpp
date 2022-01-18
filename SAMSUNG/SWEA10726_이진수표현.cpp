#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int n, m;
        cin >> n >> m;
        int temp = (1 << n) - 1;
        if (temp != (m & temp)) cout << "#" << test_case << " OFF\n";
        else cout << "#" << test_case << " ON\n";
    }
    return 0;
}