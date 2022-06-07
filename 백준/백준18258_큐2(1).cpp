//을호 코드
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int val;
    Node *next;

    explicit Node(int x) : val(x), next(nullptr) {}
};

class MyQueue {
private:
    Node *front, *tail;
    int sz;

public:
    MyQueue() {
        sz = 0;
        front = nullptr;
        tail = nullptr;
    }

    void push(int x) {
        Node *new_node = new Node(x);
        if (tail == nullptr) {
            front = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        sz++;
    }

    bool empty() {
        return sz == 0;
    }

    int size() {
        return sz;
    }

    int pop() {
        if (empty()) return -1;
        int ret = front->val;
        Node *tmp = front;
        if (front->next == nullptr) {
            front = nullptr;
            tail = nullptr;
        } else {
            front = front->next;
        }
        delete tmp;
        sz--;
        return ret;
    }

    int get_front() {
        return front == nullptr ? -1 : front->val;
    }

    int get_tail() {
        return tail == nullptr ? -1 : tail->val;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    MyQueue q;
    string str;
    while (n--) {
        cin >> str;
        if (str == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if (str == "front") cout << q.get_front() << "\n";
        else if (str == "empty") cout << q.empty() << "\n";
        else if (str == "pop") cout << q.pop() << "\n";
        else if (str == "back") cout << q.get_tail() << "\n";
        else if (str == "size") cout << q.size() << "\n";
    }
}