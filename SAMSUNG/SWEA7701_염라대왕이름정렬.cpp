#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const string arr1, const string arr2) {
    if (arr1.size() == arr2.size()) return arr1 < arr2;
    return arr1.size() < arr2.size();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t, n;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        string arr[20001];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n, compare);
        cout << '#' << tc << "\n";
        for(int i=0; i<n; i++){
            if(arr[i]!=arr[i+1]) cout << arr[i] << "\n";
        }
    }
}