#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>

using namespace std;

#define CMD_INIT       100
#define CMD_INSERT     200
#define CMD_MOVECURSOR 300
#define CMD_COUNT      400

extern void init(int H, int W, char mStr[]);

extern void insert(char mChar);

extern char moveCursor(int mRow, int mCol);

extern int countCharacter(char mChar);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#define MAX_NODE 100000
struct Node {
    char data;
    Node *prev;
    Node *next;
} node[90010];
Node *head, *tail, *rowStart[310], *nowPointer;
int charRow[27][310], cntRow[310], nowRow, nowCol, tot, H, W, minusChar[27];
int nodeCnt;

void add(Node *now, char c) {
    node[nodeCnt].data = c;
    Node *temp = &node[nodeCnt++];
    temp->next = now->next, temp->prev = now;
    now->next->prev = temp, now->next = temp;
}

int realStart;

void init(int _H, int _W, char mStr[]) {
    if (realStart == 0) {
        head = new Node(), tail = new Node();
    }
    H = _H, W = _W;
    realStart = 1;
    head->next = tail, tail->prev = head;
    nodeCnt = 0, nowRow = 1, nowCol = 1, nowPointer = head, tot = 0;
    memset(charRow, 0, sizeof(charRow));
    memset(cntRow, 0, sizeof(cntRow));
    memset(minusChar, 0, sizeof(minusChar));
    rowStart[1] = head;
    Node *now = head;
    for (int i = 1; mStr[i - 1] != 0; i++) {
        int nowRow1 = (i - 1) / W + 1;
        add(now, mStr[i - 1]);
        charRow[mStr[i - 1] - 'a' + 1][nowRow1]++;
        cntRow[nowRow1]++;
        tot++;
        now = now->next;
        if (i % W == 0) rowStart[nowRow1 + 1] = now;
    }
}

void insert(char mChar) {
    add(nowPointer, mChar);
    tot++;
    charRow[mChar - 'a' + 1][nowRow]++, cntRow[nowRow]++, minusChar[mChar - 'a' + 1]++;
    for (int i = nowRow; i <= H; i++) {
        if (cntRow[i] <= W) {
            if (cntRow[i] == W) {
                rowStart[i + 1] = tail->prev;
            }
            break;
        }
        charRow[rowStart[i + 1]->data - 'a' + 1][i]--;
        cntRow[i]--;
        charRow[rowStart[i + 1]->data - 'a' + 1][i + 1]++;
        cntRow[i + 1]++;
        rowStart[i + 1] = rowStart[i + 1]->prev;
    }
    nowCol++;
    if (nowCol > W) {
        nowRow++, nowCol = 1;
        memset(minusChar, 0, sizeof(minusChar));
    }
    nowPointer = nowPointer->next;
}

char moveCursor(int mRow, int mCol) {
    memset(minusChar, 0, sizeof(minusChar));
    nowRow = mRow, nowCol = mCol;
    if ((mRow - 1) * W + mCol > tot) {
        nowRow = tot / W + 1, nowCol = tot % W + 1;
    }
    nowPointer = rowStart[nowRow];
    for (int i = 0; i < nowCol - 1; i++) {
        if (nowPointer->next == tail) return '$';
        minusChar[nowPointer->next->data - 'a' + 1]++;
        nowPointer = nowPointer->next;
    }
    if (nowPointer->next == tail) return '$';
    return nowPointer->next->data;
}

int countCharacter(char mChar) {
    int ret = 0;
    for (int i = nowRow; cntRow[i] != 0; i++) ret += charRow[mChar - 'a' + 1][i];
    return ret - minusChar[mChar - 'a' + 1];
}

static bool run() {
    bool correct = false;
    int queryCnt;
    scanf("%d", &queryCnt);
    int H, W;
    char mChar;
    static char mStr[90001];

    while (queryCnt--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == CMD_INIT) {
            scanf("%d %d %s", &H, &W, mStr);
            init(H, W, mStr);
            correct = true;
        } else if (cmd == CMD_INSERT) {
            scanf(" %c", &mChar);
            insert(mChar);
        } else if (cmd == CMD_MOVECURSOR) {
            int mRow, mCol;
            scanf("%d %d", &mRow, &mCol);

            char ret = moveCursor(mRow, mCol);

            char ans;
            scanf(" %c", &ans);
            if (ret != ans) {
                correct = false;
            }
        } else if (cmd == CMD_COUNT) {
            scanf(" %c", &mChar);

            int ret = countCharacter(mChar);

            int ans;
            scanf("%d", &ans);
            if (ret != ans) {
                correct = false;
            }
        }
    }
    return correct;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++) {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}