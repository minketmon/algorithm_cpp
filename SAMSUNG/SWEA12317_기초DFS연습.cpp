#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>

using namespace std;
static unsigned int seed = 12345;

static unsigned int pseudo_rand(int max) {
    seed = ((unsigned long long) seed * 1103515245 + 12345) & 0x7FFFFFFF;
    return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)
extern void dfs_init(int N, int path[MAX_N][2]);

extern int dfs(int k);

static int p[MAX_K + 2];
static int c[MAX_K + 2];
static int path[MAX_N][2];

int child_cnt[100] = {0};
int child_list[100][MAX_CHILD] = {0};

static void makeTree(int n) {
    for (int i = 1; i < MAX_K + 2; ++i) {
        p[i] = c[i] = -1;
    }
    c[pseudo_rand(MAX_K + 1) + 1] = 0;
    for (int i = 0; i < n; ++i) {
        int pi = pseudo_rand(MAX_K + 1) + 1;
        while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
            ++pi;
            if (pi == MAX_K + 2)
                pi = 1;
        }
        int ci = pseudo_rand(MAX_K + 1) + 1;
        while (c[ci] >= 0) {
            ++ci;
            if (ci == MAX_K + 2)
                ci = 1;
        }
        p[ci] = pi;
        ++c[pi];
        c[ci] = 0;
    }
    bool check[MAX_K + 2] = {false};
    for (int i = 0; i < n; ++i) {
        int e = pseudo_rand(MAX_K + 1) + 1;
        while (check[e] || c[e] < 0 || p[e] == -1) {
            ++e;
            if (e == MAX_K + 2)
                e = 1;
        }
        check[e] = true;
        path[i][0] = p[e];
        path[i][1] = e;
    }
}

void dfs_init(int N, int path[100][2]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < MAX_CHILD; j++) {
            child_list[i][j] = 0;
        }
        child_cnt[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int par = path[i][0];
        int child = path[i][1];
        child_list[par][child_cnt[par]] = child;
        child_cnt[par]++;
    }
}

int dfs(int n) {
    int ret = -1;
    bool visited[100] = {false};
    int st[100], top = -1;
    st[++top] = n;
    while (top != -1) {
        int cur = st[top--];
        if (!visited[cur]) {
            visited[cur] = true;
            for (auto next: child_list[cur]) {
                if (!visited[next]) {
                    if (next > n) {
                        ret = next;
                        break;
                    }
                    st[++top] = next;
                }
            }
        }
    }
    return ret;
}

int main() {
    setbuf(stdout, NULL);
    int T;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);

    int totalScore = 0;
    for (int tc = 1; tc <= T; tc++) {//
        int n, q;

        scanf("%d %d %d", &n, &q, &seed);

        makeTree(n - 1);
        dfs_init(n, path);

        bool check[MAX_K + 2] = {false};

        int score = 100;
        for (int i = 0; i < q; ++i) {
            int k, ret, correct;

            scanf("%d", &k);
            ret = dfs(k);

            scanf("%d", &correct);

            if (ret != correct) {
                cout << "k : " << k << ", ret : " << ret << ", ans : " << correct << "\n";
                score = 0;
            }
        }
        printf("#%d : %d\n", tc, score);
        totalScore += score;
    }
    printf("#total score : %d\n", totalScore / T);

    return 0;
}