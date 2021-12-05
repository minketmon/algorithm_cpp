#include <iostream>

using namespace std;
int arr[100001];

int main() {
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