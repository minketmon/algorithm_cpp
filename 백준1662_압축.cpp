#include <iostream>
#include <stack>

using namespace std;

string s;
int arr[50];

int getLength(int start, int end) {
    int result = 0;
    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            int K = s[i - 1] - '0';
            result += K * getLength(i + 1, arr[i]) - 1;
            i = arr[i];
            continue;
        }
        result++;
    }
    return result;
}

int main() {
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            arr[st.top()] = i;
            st.pop();
        }
    }
    cout << getLength(0, s.length());
}