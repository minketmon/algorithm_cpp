#include <iostream>

#define INF 123456789
using namespace std;
int edge[101][101];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            edge[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(edge[a][b]!=0) {
            if(edge[a][b] > c) edge[a][b] = c;
        } else edge[a][b] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(edge[i][k]==INF) continue;
            for(int j=1; j<=n; j++){
                if(edge[k][j]==INF) continue;
                if(edge[i][j] > edge[i][k]+edge[k][j]) {
                    edge[i][j] = edge[i][k]+edge[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<= n; j++){
            if(i==j) cout << 0 << " ";
            else if(edge[i][j]==INF) cout << 0 << " ";
            else cout << edge[i][j] << " ";
        }cout << "\n";
    }
}
