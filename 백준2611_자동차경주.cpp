#include <iostream>
#include <vector>

using namespace std;
int n, m;
bool basic[101];
vector<int> v[101];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> k;
        for(int i=0; i<k; i++)
            v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        for(auto a: v[i])
            cout << a << " ";
        cout << "\n";
    }
}
