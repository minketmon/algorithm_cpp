#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int score[101];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        int sub1, sub2;
        cin >> sub1 >> sub2;
        if (sub2 <= l) {
            v.push_back(1);
        } else if(sub1 <= l) v.push_back(0);
    }
    sort(v.begin(), v.end(), greater());
    int answer = 0;
    if(v.size() < k) {
        for(int i: v) {
            if(i) answer += 140;
            else answer += 100;
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            if (v[i]) answer += 140;
            else answer += 100;
        }
    }
    cout << answer;
}
