#include <iostream>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a = 10, b = 30;
    // 01010 10100 10100
    // 11110 11110 01010
    a ^= b; // 10100
    cout << a << "\n";
    b ^= a; // 01010
    cout << b << "\n";
    a ^= b; // 11110
    cout << a << "\n";
}
