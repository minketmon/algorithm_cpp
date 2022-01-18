#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
#define MAX_NODE 10000

enum {
    ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99
};

extern void init();

extern void addNode2Head(int data);

extern void addNode2Tail(int data);

extern void addNode2Num(int data, int num);

extern void removeNode(int data);

extern int getList(int output[MAX_NODE]);

#define MAX_NODE 10000

struct Node {
    int data;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data) {
    Node *new_node = getNode(data);
    new_node->next = head->next;
    head->next = new_node;
}

void addNode2Tail(int data) {
    Node *new_node = getNode(data);
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = nullptr;
}

void addNode2Num(int data, int num) {
    Node *new_node = getNode(data);
    Node *temp = head;
    for (int i = 0; i < num - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void removeNode(int data) {
    Node *temp = head;
    while (temp->next) {
        if (temp->next->data == data) break;
        temp = temp->next;
    }
    if (temp->next != nullptr) temp->next = temp->next->next;
}

int getList(int output[MAX_NODE]) {
    Node *temp = head;
    int cnt = 0;
    while (temp->next) {
        temp = temp->next;
        output[cnt] = temp->data;
        cnt++;
    }
    return cnt;
}

static void run() {
    while (1) {
        int cmd, data, num, cnt, i;
        int output[MAX_NODE] = {0};

        scanf("%d", &cmd);
        switch (cmd) {
            case ADD_HEAD:
                scanf("%d", &data);
                addNode2Head(data);
                break;
            case ADD_TAIL:
                scanf("%d", &data);
                addNode2Tail(data);
                break;
            case ADD_NUM:
                scanf("%d %d", &data, &num);
                addNode2Num(data, num);
                break;
            case REMOVE:
                scanf("%d", &data);
                removeNode(data);
                break;
            case PRINT:
                cnt = getList(output);
                i = 0;
                while (cnt--)
                    printf("%d ", output[i++]);
                printf("\n");
                break;
            case END:
                return;
        }
    }
}

int main(void) {
    //setbuf(stdout, NULL);
    //freopen("sll_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("#%d\n", t);
        init();
        run();
        printf("\n");
    }

    return 0;
}