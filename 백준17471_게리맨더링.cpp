#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, pop[101], visited[101], visited2[101];
int _min = 123456789;
vector<int> v[101];
vector<int> a, b;

void combination(int idx, int cnt, int k) {
    if (cnt == k) {
        a.clear(), b.clear();
        memset(visited2, -1, sizeof(visited2));
        for (int i = 0; i < n; i++) {
            if (visited[i] == true) a.push_back(i + 1);
            else b.push_back(i + 1);
        }
        queue<int> q;
        q.push(a[0]);
        visited2[a[0]] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next: v[cur]) {
                bool flag = false;
                for (auto a: a) if (next == a) flag = true;
                if (!flag) continue;
                if (visited2[next] == 1) continue;
                visited2[next] = true;
                q.push(next);
            }
        }
        for (auto a: a)
            if (visited2[a] == -1) return;
        memset(visited2, -1, sizeof(visited2));
        q.push(b[0]);
        visited2[b[0]] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next: v[cur]) {
                bool flag = false;
                for (auto b: b) if (next == b) flag = true;
                if (!flag) continue;
                if (visited2[next] == 1) continue;
                visited2[next] = true;
                q.push(next);
            }
        }
        for (auto b: b)
            if (visited2[b] == -1) return;
        int a_pop = 0, b_pop = 0;
        for (auto a: a) a_pop += pop[a];
        for (auto b: b) b_pop += pop[b];
        int gap = abs(a_pop - b_pop);
        _min = min(_min, gap);
        return;
    }
    for (int i = idx; i < n; i++) {
        if (visited[i] == true) continue;
        visited[i] = true;
        combination(i, cnt + 1, k);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pop[i];
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int d;
            cin >> d;
            v[i].push_back(d);
        }
    }
    for (int i = 1; i < n; i++) combination(0, 0, i);
    if (_min == 123456789) cout << -1;
    else cout << _min;
}