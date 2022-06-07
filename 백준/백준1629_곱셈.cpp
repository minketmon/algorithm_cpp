#include <iostream>
#include <vector>

using namespace std;
long long mod[33];
vector<int> v;

int main() {
    long long a, b, c;
    long long ans = 1;
    cin >> a >> b >> c;
    mod[0] = a % c;
    for (int i = 1; i <= 32; i++) {
        mod[i] = (mod[i - 1] * mod[i - 1]) % c;
    }

    //이진수로 바꾸기
    while (b > 0) {
        if (b % 2 == 0)
            v.push_back(0);
        else v.push_back(1);
        b = b / 2;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i])
            ans = mod[i] * ans % c;
    }
    cout << ans;
}