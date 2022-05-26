#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int composite[10000010];
char arr[9];
vector<int> vec;

void Eratos() {
    composite[1] = true;
    for (int i = 2; i * i <= 10000000; i++) {
        if (composite[i]) continue;
        for (int j = 2 * i; j <= 10000000; j += i) {
            composite[j] = true;
        }
    }
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutation(char data[], int depth, int n, int r) {
    if (depth == r) {
        string s;
        for (int i = 0; i < r; i++)
            s += data[i];
        vec.push_back(stoi(s));
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(data[depth], data[i]);
        permutation(data, depth + 1, n, r);
        swap(data[depth], data[i]);
    }
}

int solution(string numbers) {
    Eratos();
    int answer = 0;
    for (int i = 0; i < numbers.size(); i++) arr[i] = numbers[i];
    for (int i = 1; i <= numbers.size(); i++) permutation(arr, 0, numbers.size(), i);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (auto a: vec) {
        if (a == 0) continue;
        if (!composite[a]) answer++;
    }
    return answer;
}