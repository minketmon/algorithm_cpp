#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> v(W);
    for(int i=0; i<W; i++) {
        cin >> v[i];
    }
    int result = 0;
    for(int i=1; i<W-1; i++) {
        int x=0, y=0;
        for(int j=0; j<i; j++) {
            x = max(x, v[j]);
        }
        for(int j=i+1; j<W; j++){
            y = max(y, v[j]);
        }
        int add = min(x, y) - v[i];
        if(add<=0) add = 0;
        result += add;
    }
    cout << result;
}