#include <iostream>

using namespace std;
int arr[50] = {0};
int idx = 0;

void push() {
    arr[idx]++;
    idx++;
}

int pop() {
    if (idx == 0) return -1;
    arr[idx - 1] = 0;
    idx--;
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') push();
            else if (s[i] == ')') {
                if (pop() == -1) {
                    cout << "NO\n";
                    idx = -1;
                    break;
                }
            }
        }
        if (idx > 0) {
            cout << "NO\n";
        } else if (idx == 0) cout << "YES\n";
        idx = 0;
        arr[50] = {0};
    }
}