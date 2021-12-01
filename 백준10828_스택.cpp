#include <iostream>
using namespace std;
#define MAX 10000
int idx = 0;
int arr[MAX] = {0};

void push(int num) {
    arr[idx] = num;
    idx++;
}
int pop() {
    if(idx==0) return -1;
    int temp = arr[idx-1];
    idx--;
    return temp;
}
int size() {
    return idx;
}
int empty() {
    if(idx==0) return 1;
    else return 0;
}
int top() {
    if(idx==0) return -1;
    return arr[idx-1];
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s=="push") {
            int num;
            cin >> num;
            push(num);
        }
        else if(s=="pop") cout << pop() << "\n";
        else if(s=="size") cout << size() << "\n";
        else if(s=="empty") cout << empty() << "\n";
        else if(s=="top") cout << top() << "\n";
    }
}
