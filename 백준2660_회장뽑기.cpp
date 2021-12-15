#include <iostream>

#define INF 123456789
using namespace std;
int n, dist[51][51];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = INF;
        }
    }
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        dist[a][a] = 0;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dist[i][j] << " ";
        }cout << "\n";
    }
}