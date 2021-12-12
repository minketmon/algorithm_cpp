#include<iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;
int Arr[1001];
bool Select[1001];

void Print() {
    for (int i = 0; i < n; i++) {
        if (Select[i] == true) {
            cout << v[i] << " ";
        }
    }
    cout << endl;
}

void DFS(int Idx, int Cnt) {
    if (Cnt == k) {
        Print();
        return;
    }

    for (int i = Idx; i < n; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}

int main(void) {
    cin >> n >> k;
    for(int i=1; i<=n; i++)v.push_back(i);

    DFS(0, 0);
}