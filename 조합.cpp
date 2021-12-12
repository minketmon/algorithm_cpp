#include <iostream>
#include <vector>

using namespace std;
int n, k;
bool visited[1000];
vector<int> v;

void dfs(int idx, int cnt) {
    if(cnt==k){
        for(int i=0; i<n; i++){
            if(visited[i]==true) cout << v[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]==true) continue;
        visited[i] = true;
        dfs(i, cnt+1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) v.push_back(i);
    dfs(0, 0);
}