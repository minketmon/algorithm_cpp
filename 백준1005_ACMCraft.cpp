#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int tc, n, k, w, t[1001], in[1001];

void sol() {
    priority_queue<pair<int, int>> pq;
    vector<int> v[1001];
    memset(in, 0, sizeof(in));
    memset(t, 0, sizeof(t));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    cin >> w;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) pq.push({-t[i], i});
    }

    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if (cur == w) {
            cout << d << "\n";
            return;
        }
        for (auto a: v[cur]) {
            in[a]--;
            if (in[a] == 0) {
                pq.push({-(d + t[a]), a});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> tc;
    while (tc--) {
        sol();
    }
}

/*200607
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int tc, n, k, w, t[1001], in[1001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> tc;
    while(tc--) {
        memset(in, 0, sizeof(in));
        memset(t, 0, sizeof(t));
        vector<int> vec[1001];
        priority_queue<pair<int, int>> pq;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> t[i];
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            in[b]++;
        }
        cin >> w;
        for (int i = 1; i <= n; i++) if (in[i] == 0) pq.push({-t[i], i});
        while (!pq.empty()) {
            int cur = pq.top().second;
            int tt = -pq.top().first;
            pq.pop();
            if (cur == w) {
                cout << tt << '\n';
                break;
            }
            for (auto a: vec[cur]) {
                in[a]--;
                if (in[a] == 0) pq.push({-(tt + t[a]), a});
            }
        }
    }
}
 *