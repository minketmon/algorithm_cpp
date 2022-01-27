#include <iostream>

using namespace std;
int n, k, w[200001], s[200001];

bool check(int mid) {
    int index = -1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < s[i]; j++) {
            index++;
            if (index == n) return false;
            if (w[index] > mid) {
                i--;
                break;
            }
        }
    }
    return true;
}

int search(){
    int left = 0, right = 200000;
    while (left < right) {
        int mid = (left + right) / 2;
        if (!check(mid)) left = mid + 1;
        else right = mid;
    }
    return right;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> w[i];
        for (int i = 0; i < k; i++) cin >> s[i];
        cout << '#' << tc << " " << search() << "\n";
    }
}