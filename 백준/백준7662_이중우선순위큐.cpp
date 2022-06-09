#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
int k;
bool visited[1000001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int cnt = 0;
        priority_queue<pair<int, int>> max;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;
        cin >> k;
        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'I') {
                max.push({num, i});
                min.push({num, i});
                visited[i] = true;
                cnt++;
            } else {
                if (cnt == 0) continue;
                if (num == 1) {
                    while (!max.empty() && !visited[max.top().second]) max.pop();
                    if (!max.empty()) {
                        visited[max.top().second] = false;
                        max.pop();
                    }
                } else {
                    while (!min.empty() && !visited[min.top().second]) min.pop();
                    if (!min.empty()) {
                        visited[min.top().second] = false;
                        min.pop();
                    }
                }
                cnt--;
            }
        }

        if (cnt == 0 || min.empty() || max.empty()) {
            cout << "EMPTY\n";
            continue;
        }
        while (!max.empty() && !visited[max.top().second]) max.pop();
        while (!min.empty() && !visited[min.top().second]) min.pop();
        cout << max.top().first << ' ' << min.top().first << '\n';
    }
}