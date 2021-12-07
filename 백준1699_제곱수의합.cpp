#include <iostream>

using namespace std;
int arr[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        arr[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }
    cout << arr[n];
}