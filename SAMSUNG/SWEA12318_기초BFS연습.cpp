#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

extern void bfs_init(int N, int map[10][10]);

extern int bfs(int x1, int y1, int x2, int y2);

struct Pair {
    int a, b;
};
int map_sz, map[10][10];
int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};
bool visited[10][10];

static int test_bfs() {
    int N;
    int map[10][10];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs_init(N, map);
    int M;
    int score = 100;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = bfs(x1, y1, x2, y2);
        int dist;
        scanf("%d", &dist);
        cout << "res" << result << " dist" << dist << "\n";
        if (result != dist) score = 0;
    }
    return score;
}

void bfs_init(int map_size, int _map[10][10]) {
    map_sz = map_size;
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            map[i][j] = _map[i][j];
        }
    }
}

int bfs(int y1, int x1, int y2, int x2) {
    x1--, y1--, x2--, y2--;
    for (int i = 0; i < map_sz; i++) {
        for (int j = 0; j < map_sz; j++) {
            visited[i][j] = false;
        }
    }
    int front = -1, rear = -1;
    Pair q[100];
    int dist[100];
    visited[x1][y1] = true;
    q[++rear] = {x1, y1};
    dist[rear] = 0;
    while (front != rear) {
        int cur_x = q[++front].a;
        int cur_y = q[front].b;
        int d = dist[front];
        if (cur_x == x2 && cur_y == y2) {
            return d;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + x[i];
            int ny = cur_y + y[i];
            if (nx < 0 || ny < 0 || nx >= map_sz || ny >= map_sz) continue;
            if (map[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q[++rear].a = nx;
            q[rear].b = ny;
            dist[rear] = d + 1;
        }
    }
    return -1;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
    printf("#total score : %d\n", test_bfs());

    return 0;
}