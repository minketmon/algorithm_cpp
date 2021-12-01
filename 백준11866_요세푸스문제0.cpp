#include <iostream>

#define MAX 2000000
int arr[MAX] = {0};
int fr = 0, bk = 0;
using namespace std;

void push(int num) {
    arr[bk++] = num;
}

int pop() {
    return arr[fr++];
}

int size() {
    return bk - fr;
}

int front() {
    return arr[fr];
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    bk = n;
    cout << "<";
    while (size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            push(front());
            pop();
        }
        cout << pop() << ", ";
    }
    cout << pop() << ">";
}