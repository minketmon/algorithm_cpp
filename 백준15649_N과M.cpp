#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10], order[10], visited[10], n, r;
vector<vector<int>> res;

void swap(int &a, int &b) {
    int temp = a;
    a = b, b = temp;
}
void dfs(int depth) {
    if(depth == r) {
        vector<int> v;
        for (int i = 0; i < r; i++) v.push_back(arr[i]);
        res.push_back(v);
        return;
    }
    for (int i = depth; i < n; i++) {
        swap(arr[depth], arr[i]);
        dfs(depth+1);
        swap(arr[i], arr[depth]);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 0; i < n; i++) arr[i] = i+1;
    dfs(0);
    sort(res.begin(), res.end());
    for(auto r : res) {
        for(auto x : r) {
            cout << x << ' ';
        }cout << '\n';
    }
}