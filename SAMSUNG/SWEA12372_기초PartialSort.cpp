#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;
#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();

extern void addUser(int uID, int income);

extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;
using namespace std;

#define MAX 100001
int max_cnt = 0;
struct User {
    int id, income;
};
User user[MAX];

void init() {
    max_cnt = 0;
}

void addUser(int uID, int height) {
    int cur = max_cnt;
    user[max_cnt++] = {uID, height};
    while (cur > 0) {
        int parent = (cur - 1) / 2;
        if (user[cur].income < user[parent].income) break;
        if (user[cur].income == user[parent].income) if (user[cur].id > user[parent].id) break;
        User temp = user[cur];
        user[cur] = user[parent];
        user[parent] = temp;
        cur = parent;
    }
}

int getTop10(int result[10]) {
    int count = max_cnt;
    if (count > 10) count = 10;
    User temp[10];
    for (int i = 0; i < count; i++) {
        result[i] = user[0].id;
        temp[i] = user[0];
        user[0] = user[--max_cnt];
        int cur = 0, child;
        while (cur * 2 + 1 < max_cnt) {
            int left = cur * 2 + 1, right = cur * 2 + 2;
            if (cur * 2 + 2 == max_cnt) child = left;
            else {
                if (user[left].income > user[right].income) child = left;
                else if (user[left].income < user[right].income) child = right;
                else { if (user[left].id < user[right].id) child = left; else child = right; }
            }
            if (user[cur].income > user[child].income) break;
            if (user[cur].income == user[child].income) if (user[cur].id < user[child].id) break;
            User t = user[cur];
            user[cur] = user[child];
            user[child] = t;
            cur = child;
        }
    }
    for (int i = 0; i < count; i++) addUser(temp[i].id, temp[i].income);
    return count;
}

static unsigned int pseudoRand() {
    seed = seed * 214013 + 2531011;
    return (unsigned int) (seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
    for (int i = 0; i < inputLen; i++) {
        input[i] = pseudoRand();
    }
}

static int run() {
    int N, userNum, uID = 0;
    int score = 100, result[10], cnt;
    int sum, check;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &userNum);
        makeInput(userNum);
        for (int j = 0; j < userNum; j++) {
            addUser(uID++, input[j]);
        }
        cnt = getTop10(result);

        sum = 0;
        for (int j = 0; j < cnt; j++) {
            sum += result[j];
        }
        scanf("%d", &check);
        if (check != sum)
            score = 0;
    }
    return score;
}

int main(void) {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        init();
        printf("#%d %d\n", tc, run());
    }
    return 0;
}