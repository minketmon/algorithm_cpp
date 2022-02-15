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
#include <cstring>

#define MAX_NODE 100000
struct Node {
    char data;
    Node *next, *prev;
} node[90001];
int h, w, cur_row, cur_col, total, node_cnt;
Node *head, *tail, *row[301], *now;
int cnt[301][27], row_cnt[301], min_char[27];

void add(Node *now, char mChar) {
    node[node_cnt].data = mChar;
    Node *temp = &node[node_cnt++];
    temp->next = now->next;
    now->next->prev = temp;
    temp->prev = now, now->next = temp;
}

void init(int H, int W, char mStr[]) {
    head = new Node(), tail = new Node();
    h = H, w = W, cur_row = 1, cur_col = 1, total = 0, node_cnt = 0;
    head->next = tail, tail->prev = head;
    row[1] = head, now = head;
    memset(cnt, 0, sizeof(cnt));
    memset(row_cnt, 0, sizeof(row_cnt));
    memset(min_char, 0, sizeof(min_char));
    Node *temp = head;
    for (int i = 1; mStr[i - 1] != 0; i++) {
        add(temp, mStr[i - 1]);
        int curr = (i - 1) / w + 1;
        cnt[curr][mStr[i - 1] - 'a']++, row_cnt[curr]++, total++;
        temp = temp->next;
        if (i % w == 0) row[curr + 1] = temp;
    }
}

void insert(char mChar) {
    add(now, mChar);
    cnt[cur_row][mChar - 'a']++, row_cnt[cur_row]++, min_char[mChar - 'a']++;
    for (int i = cur_row; i <= h; i++) {
        if (row_cnt[i] <= w) {
            if (row_cnt[i] == w) row[i + 1] = tail->prev;
            break;
        } else {
            cnt[i][row[i + 1]->data - 'a']--;
            cnt[i + 1][row[i + 1]->data - 'a']++;
            row_cnt[i]--, row_cnt[i + 1]++;
            row[i + 1] = row[i + 1]->prev;
        }
    }
    if (w < ++cur_col) {
        cur_row++, cur_col = 1;
        memset(min_char, 0, sizeof(min_char));
    }
    total++;
    now = now->next;
}

char moveCursor(int mRow, int mCol) {
    memset(min_char, 0, sizeof(min_char));
    cur_row = mRow, cur_col = mCol;
    if (mCol + (mRow - 1) * w > total) cur_col = total % w + 1, cur_row = total / w + 1;
    now = row[cur_row];
    for (int i = 0; i < cur_col - 1; i++) {
        min_char[now->next->data - 'a']++;
        now = now->next;
    }
    if (now->next == tail) return '$';
    else return now->next->data;
}


int countCharacter(char mChar) {
    int ans = 0;
    for (int i = cur_row; row_cnt[i] != 0; i++)
        ans += cnt[i][mChar - 'a'];
    ans -= min_char[mChar - 'a'];
    return ans;
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
            if (ret != ans)cout << ret << ' ' << ans << '\n';
            if (ret != ans) {
                correct = false;
            }
        } else if (cmd == CMD_COUNT) {
            scanf(" %c", &mChar);

            int ret = countCharacter(mChar);

            int ans;
            scanf("%d", &ans);
            if (ret != ans) cout << ret << ' ' << ans << '\n';
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