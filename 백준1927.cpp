#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX] = {0};
int fr = 1;
int bk = 1;

void swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}
void push(int num, int idx) {
    arr[bk++] = num;
    int parent = idx/2;
    while(parent >= 1) {
        if(arr[parent] > arr[idx]) {
            swap(arr[parent], arr[idx]);
            idx = parent;
            parent = idx/2;
        }
        else break;
    }
}
int pop() {
    if(bk-fr==0) return 0;
    int temp = arr[fr];
    int idx = 1;
    int left = idx*2;
    int right = left+1;
    arr[idx] = arr[bk-1];
    while(left < bk && right < bk) {
        if(arr[left] <= arr[right] ) {
            if(arr[idx] > arr[left]) {
                swap(arr[idx], arr[left]);
                idx = left;
                left = idx*2;
            }
            else break;
        }
        else if(arr[left] > arr[right]) {
            if(arr[idx] > arr[right]) {
                swap(arr[idx], arr[right]);
                idx = right;
                left = idx*2;
            }
            else break;
        }
        right = left+1;
    }
    arr[bk-1] = 0;
    bk--;
    return temp;
}
int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if(x==0) {
            cout << pop() << "\n";
        }
        else {
            push(x, bk);
        }
    }
}