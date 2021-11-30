#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
bool visited[MAX] = {0};
int parent[MAX];

void find_parent(int root) {
    visited[root] = true;
    for(int i=0; i<v[root].size(); i++) {
        int child = v[root][i];
        if(visited[child] == false) {
            parent[child] = root;
            find_parent(child);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    find_parent(1);

    for(int i=2; i<=n; i++) {
        cout << parent[i] << "\n";
    }
}