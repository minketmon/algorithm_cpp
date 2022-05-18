#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int sum1, sum2, ans;
queue<int> q1, q2;
vector<int> v;

void dfs(int idx, int cnt, int sum1, int sum2) {
    if (sum1 == sum2) {
        if (cnt < ans) ans = cnt;
        return;
    }
    int q1_top = q1.front();
    int q2_top = q2.front();
    cout << cnt << ' ' << sum1 << ' ' << sum2 << '\n';
    if (sum1 > sum2) {
        if (!q1.empty()) {
            cout << "\n=======================\n";
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            q1.pop();
            q2.push(q1_top);
            sum1 -= q1_top;
            sum2 += q1_top;
            cout << "q1_top : " << q1_top << '\n';
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            dfs(idx, cnt + 1, sum1, sum2);
        }
        if (!q2.empty()) {
            cout << "\n=======================\n";
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            q2.pop();
            q1.push(q2_top);
            sum1 += q2_top;
            sum2 -= q2_top;
            cout << "q2_top : " << q2_top << '\n';
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            dfs(idx, cnt + 1, sum1, sum2);
        }
    } else {
        if (!q2.empty()) {
            cout << "\n=======================\n";
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            q2.pop();
            q1.push(q2_top);
            sum1 += q2_top;
            sum2 -= q2_top;
            cout << "q2_top : " << q2_top << '\n';
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            dfs(idx, cnt + 1, sum1, sum2);
        }
        if (!q1.empty()) {
            cout << "\n=======================\n";
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            q1.pop();
            q2.push(q1_top);
            sum1 -= q1_top;
            sum2 += q1_top;
            cout << "q1_top : " << q1_top << '\n';
            cout << "sum1 : " << sum1 << '\n';
            cout << "sum2 : " << sum2 << '\n';
            dfs(idx, cnt + 1, sum1, sum2);
        }
    }
}

int solution(vector<int> queue1, vector<int> queue2) {
    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i], sum2 += queue2[i];
        q1.push(queue1[i]), q2.push(queue2[i]);
    }
    dfs(0, 0, sum1, sum2);
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ans = 123456789;

    vector<int> queue1, queue2;
    queue1.push_back(3);
    queue1.push_back(2);
    queue1.push_back(7);
    queue1.push_back(2);

    queue2.push_back(4);
    queue2.push_back(6);
    queue2.push_back(5);
    queue2.push_back(1);

    int answer = 0;
    int n = queue1.size();
    queue<long long> q1, q2;
    long long sum, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    sum = sum1 + sum2;
    if (sum % 2) {
        cout << -1;
        return 0;
    }
    while (answer <= 3 * n) {
        long long t;
        if (sum1 > sum2) {
            t = q1.front();
            q1.pop();
            q2.push(t);
            sum1 -= t;
            sum2 += t;
        } else if (sum2 > sum1) {
            t = q2.front();
            q2.pop();
            q1.push(t);
            sum2 -= t;
            sum1 += t;
        } else {
            cout << answer;
            return 0;
        }
        answer++;
    }
    answer =  -1;

    cout << answer << "\n";
}