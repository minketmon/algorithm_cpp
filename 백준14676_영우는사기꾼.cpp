#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, k, in[100001];
vector<int> v[100001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
}