#include <iostream>
#include <cmath>
#include <vector>

#define swap(a, b) {int temp = a, a = b, b = a;}
#define MAX_NODE 100001
using namespace std;
int depth[MAX_NODE];
int anc[MAX_NODE][20];
vector<int> graph[MAX_NODE];
int max_level;

void getTree(int here, int parent) {
    depth[here] = depth[parent] + 1;
    anc[here][0] = parent;
    max_level = (int) floor((log2(MAX_NODE)));
    for (int i = 1; i <= max_level; i++) {
        int temp = anc[here][i - 1];
        anc[here][i] = anc[temp][i - 1];
    }
    int len = graph[here].size();
    for (int i = 0; i < len; i++) {
        int there = graph[here][i];
        if (there != parent) getTree(there, here);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    depth[0] = -1;
    getTree(1, 0);
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b]) swap(a, b);

            for (int i = max_level; i >= 0; i--) {
                if (depth[a] <= depth[anc[b][i]]) b = anc[b][i];
            }
        }
        int lca = a;
        if (a != b) {
            for (int i = max_level; i >= 0; i--) {
                if (anc[a][i] != anc[b][i]) {
                    a = anc[a][i];
                    b = anc[b][i];
                }
                lca = anc[a][i];
            }
        }
        cout << lca << "\n";
    }
}