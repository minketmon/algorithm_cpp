#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int tc, t, n, a, b;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        long long ans = 0;
        priority_queue<int> max_heap;
        priority_queue<int> min_heap;
        cin >> n >> a;
        max_heap.push(a);
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (a < max_heap.top()) max_heap.push(a);
            else min_heap.push(-a);
            if (b < max_heap.top()) max_heap.push(b);
            else min_heap.push(-b);

            if (max_heap.size() < min_heap.size()) {
                max_heap.push(-min_heap.top());
                min_heap.pop();
            } else if (max_heap.size() - 1 > min_heap.size()) {
                min_heap.push(-max_heap.top());
                max_heap.pop();
            }
            ans += max_heap.top();
            ans %= 20171109;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }

}