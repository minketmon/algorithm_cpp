#include <iostream>

using namespace std;
int n, arr[21][21], gap;
bool sel[21];

void divideTeam(int i, int k) {
    if (i > n) return;
    if (k == n / 2) {
        int start = 0, link = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (sel[i] && sel[j]) start += arr[i][j];
                else if (!sel[i] && !sel[j]) link += arr[i][j];
            }
        }
        gap = abs(start - link) < gap ? abs(start - link) : gap;
        return;
    }
    sel[i] = true;
    divideTeam(i + 1, k + 1);
    sel[i] = false;
    divideTeam(i + 1, k);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    gap = 987654321;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    divideTeam(0, 0);
    cout << gap;
}