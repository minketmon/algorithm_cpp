#include <iostream>
#define MAX 2000000
using namespace std;
int arr[MAX] = {0};
int fr = 0, bk = 0;

void push(int num) {
    bk++;
    arr[bk] = num;
}
int empty() {
    if(fr == bk) return 1;
    else return 0;
}
int pop() {
    if(empty()==1) return -1;
    int temp = arr[++fr];
    return temp;
}
int size() {
    return bk - fr;
}
int front() {
    if(empty()==1) return -1;
    return arr[fr+1];
}
int back() {
    if(empty()==1) return -1;
    return arr[bk];
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push") {
            int num;
            cin >> num;
            push(num);
        }
        else if(s == "pop") cout << pop() << "\n";
        else if(s == "size") cout << size() << "\n";
        else if(s == "empty") cout << empty() << "\n";
        else if(s == "front") cout << front() << "\n";
        else if(s == "back") cout << back() << "\n";
    }
}