#include <iostream>
using namespace std;

int N, L, H[1001], max_length, max_idx, result = 0;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> L;
        cin >> H[L];
        if(max_length < H[L]) max_length = H[L], max_idx = L;
    }

    int cur = 0;
    for(int i=1; i<max_idx; i++) {
        if(cur < H[i]) cur = H[i];
        result += cur;
    }
    cur = 0;
    for(int i=1000; i>max_idx; i--) {
        if(cur < H[i]) cur = H[i];
        result += cur;
    }
    result += max_length;
    cout << result;
}