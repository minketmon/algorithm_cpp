#include <vector>

using namespace std;
int tree[1500];

int solution(vector<vector<int>> triangle) {
    int max = 0, idx = 0;
    tree[idx++] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) tree[idx] = tree[idx - i] + triangle[i][j];
            else if (j == triangle[i].size() - 1) tree[idx] = tree[idx - (i + 1)] + triangle[i][j];
            else {
                int left = tree[idx - (i + 1)];
                int right = tree[idx - i];
                tree[idx] = left > right ? left + triangle[i][j] : right + triangle[i][j];
            }
            idx++;
        }
    }
    for (int i = idx - triangle.size() - 1; i < idx; i++) max = max > tree[i] ? max : tree[i];
    return max;
}