#include <queue>
#include <iostream>

using namespace std;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t, op, num;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cout << '#' << tc << ' ';
        cin >> n;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cin >> op;
            if (op == 1) {
                cin >> num;
                pq.push(num);
            } else {
                if(!pq.empty()) {
                    cout << pq.top() << ' ';
                    pq.pop();
                } else cout << -1 << ' ';
            }
        }
        cout << '\n';
    }
}