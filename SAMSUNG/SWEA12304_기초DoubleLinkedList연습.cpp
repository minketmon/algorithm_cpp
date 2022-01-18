#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;
#define MAX_NODE 10000

enum {
    ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99
};

extern void init();

extern void addNode2Head(int data);

extern void addNode2Tail(int data);

extern void addNode2Num(int data, int num);

extern int findNode(int data);

extern void removeNode(int data);

extern int getList(int output[MAX_NODE]);

extern int getReversedList(int output[MAX_NODE]);

#define MAX_NODE 10000

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data) {
    Node *new_node = getNode(data);
    if (head->next == nullptr) {
        new_node->next = head->next;
        new_node->prev = head;
        head->next = new_node;
    } else {
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
    }
}

void addNode2Tail(int data) {
    Node *new_node = getNode(data);
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = nullptr;
}

void addNode2Num(int data, int num) {
    Node *new_node = getNode(data);
    Node *temp = head;
    for (int i = 0; i < num - 1; i++) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    } else {
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

int findNode(int data) {
    Node *temp = head;
    int cnt = 1;
    while (temp->next) {
        if (temp->next->data == data) break;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void removeNode(int data) {
    Node *temp = head;
    while (temp->next) {
        if (temp->next->data == data) break;
        temp = temp->next;
    }
    if (temp->next == nullptr) return;
    temp = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    } else temp->prev->next = temp->next;
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

int getReversedList(int output[MAX_NODE]) {
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    int cnt = 0;
    while (temp->prev) {
        output[cnt] = temp->data;
        temp = temp->prev;
        cnt++;
    }
    return cnt;
}

static void run() {
    while (1) {
        int cmd, data, num, cnt, i = 0;
        int output[MAX_NODE] = {0};

        scanf("%d", &cmd);
        switch (cmd) {
            case ADD_HEAD: // 1
                scanf("%d", &data);
                addNode2Head(data);
                break;
            case ADD_TAIL: // 2
                scanf("%d", &data);
                addNode2Tail(data);
                break;
            case ADD_NUM: // 3
                scanf("%d %d", &data, &num);
                addNode2Num(data, num);
                break;
            case FIND: // 4
                scanf("%d", &data);
                num = findNode(data);
                printf("%d\n", num);
                break;
            case REMOVE: // 5
                scanf("%d", &data);
                removeNode(data);
                break;
            case PRINT: // 6
                cnt = getList(output);
                while (cnt--)
                    printf("%d ", output[i++]);
                printf("\n");
                break;
            case PRINT_REVERSE: // 7
                cnt = getReversedList(output);
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
    //freopen("dll_input.txt", "r", stdin);

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