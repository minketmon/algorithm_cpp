#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char * argv[]) {
  int mul = 1, add = 0;
  string str;
  cin >> str;
  stack < char > s;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      s.push(str[i]);
      mul *= 2;
    }
    if (str[i] == '[') {
      s.push(str[i]);
      mul *= 3;
    }
    if (str[i] == ')') {
      if (s.size() == 0 || s.top() == '[') {
        cout << 0;
        return 0;
      }
      if (str[i - 1] == '(')
        add += mul;
      s.pop();
      mul /= 2;
    }
    if (str[i] == ']') {
      if (s.size() == 0 || s.top() == '(') {
        cout << 0;
        return 0;
      }
      if (str[i - 1] == '[')
        add += mul;
      s.pop();
      mul /= 3;
    }
  }
  if (s.size() > 0) {
      cout << 0;
      return 0;
  }

  cout << add;
  return 0;
}

//(()[[]])([])