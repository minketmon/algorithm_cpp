#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, in[1001];
vector<int> v[1001], ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num, singer, next;
        cin >> num >> singer;
        num -= 1;
        while (num--) {
            cin >> next;
            v[singer].push_back(next);
            in[next]++;
            singer = next;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for (auto a: v[cur]) {
            if (--in[a] == 0) q.push(a);
        }
    }
    if(ans.size()!=n) cout << 0;
    else for(auto a: ans) cout << a << " ";
}