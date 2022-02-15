#include <iostream>
#include <algorithm>

using namespace std;
int N, M, a[3002], b[102], dp[3002][102][102][2];

int solution(int n, int m, int left, int get) {
    if (m + left > M) return dp[n][m][left][get] = 0;
    if (dp[n][m][left][get] != -1) return dp[n][m][left][get];
    int ret, temp, x = 0, y = 0, i = 0, j = 0;
    if (get == 0) {
        if (n > 0) {
            x = solution(n - 1, m, left, 0);
            y = solution(n - 1, m, left, 1);
        }
        if (left > 0) {
            i = solution(n, m, left - 1, 0);
            j = solution(n, m, left - 1, 1);
        }
        ret = x > y ? x : y;
        temp = i > j ? i : j;
        ret = ret > temp ? ret : temp;
    } else {
        if (n > 0) x = solution(n - 1, m, left, 0) + a[n - 1];
        if (m > 0) y = solution(n, m - 1, left, 0) + b[M - m];
        ret = x > y ? x : y;
    }
    return dp[n][m][left][get] = ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
//    clock_t start, finish;
//    double duration;
//    start = clock();
//    freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        int ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> a[i];
        cin >> M;
        for (int i = 0; i < M; i++) cin >> b[i];
        sort(b, b + M);
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                for (int k = 0; k <= M; k++)
                    dp[i][j][k][0] = -1, dp[i][j][k][1] = -1;

        for (int i = 0; i <= M; i++) {
            int x = solution(N, i, M - i, 0);
            int y = solution(N, i, M - i, 1);
            ans = x > ans ? x : ans;
            ans = y > ans ? y : ans;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
//    finish = clock();
//
//    duration = (double) (finish - start) / CLOCKS_PER_SEC;
//    cout << duration << "초" << endl;
}