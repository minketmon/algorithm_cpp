#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> vec;
    vector<int> ans;
    int sz = brown + yellow;
    for (int i = 1; i <= sqrt(sz); i++) {
        if (sz % i == 0) vec.push_back({i, sz / i});
    }
    for (auto a: vec)
        if (a.first * 2 + a.second * 2 - 4 == brown)
            if (a.first > a.second) return {a.first, a.second};
            else return {a.second, a.first};
}