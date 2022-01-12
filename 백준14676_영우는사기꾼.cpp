#include <iostream>
#include <vector>

using namespace std;

int n, m, k, in[100001], isbuild[100001];
bool flag;
vector<int> v[100001];

void built(int num) {
    if (in[num] <= 0) {
        isbuild[num]++;
        if (isbuild[num] == 1) for (auto a: v[num]) in[a]--;
    } else {
        flag = true;
    }
}

void destroy(int num) {
    if (isbuild[num] <= 0) {
        flag = true;
    } else {
        isbuild[num]--;
        if(isbuild[num]==0) for (auto a: v[num]) in[a]++;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) { // 건설
            built(b);
        } else {
            destroy(b);
        }
    }
    if (flag) cout << "Lier!";
    else cout << "King-God-Emperor";
}
