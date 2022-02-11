// Title : 범인 색출, Score 를 최소화하라
// 20 초
// stack Memory : 1M  (전역 변수 사용 금지)

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#include <random>
#include <iostream>

using namespace std;

extern void investigate();

const int MAX_NUM = 1000000;
static int SCORE, TOTAL_SCORE, TOTAL_TIME;
static char citizen[MAX_NUM];
static char room[MAX_NUM];
static char arrested[MAX_NUM];

extern void putIn(int n, int a);

extern int closeDoor(int n);

extern void arrest(int n);

extern void clearRoom();

#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

extern void putIn(int n, int a);

extern int closeDoor(int n);

extern void arrest(int n);

extern void clearRoom();

void investigate() {
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        putIn(cnt, i);
        if (i > 0 && i % 1000 == 999) {
            if (closeDoor(cnt) != 0) {
                v.push_back(i / 1000);
                num++;
            }
            cnt++;
        }
    }
    cout << cnt << " " << num << "\n";
    cnt = 0;
    num = 0;
    vector<int> v2;
    clearRoom();
    for (auto a: v) {
        for (int i = a * 1000; i < (a + 1) * 1000; i++) {
            putIn(cnt, i);
            if (i > 0 && i % 100 == 99) {
                if (closeDoor(cnt) != 0) {
                    v2.push_back(i / 100);
                    num++;
                }
                cnt++;
            }
        }
    }
    v.clear();
    cout << cnt << " " << num << "\n";
    cnt = num = 0;
    clearRoom();
    for (auto a: v2) {
        for (int i = a * 100; i < (a + 1) * 100; i++) {
            putIn(cnt, i);
            if (i > 0 && i % 10 == 9) {
                if (closeDoor(cnt) != 0) {
                    v.push_back(i / 10);
                    num++;
                }
                cnt++;
            }
        }
    }
    v2.clear();
    cout << cnt << " " << num << "\n";
    cnt = num = 0;
    clearRoom();
    for (auto a: v) {
        for (int i = a * 10; i < (a + 1) * 10; i++) {
            putIn(cnt, i);
            if (i > 0 && i % 2 == 1) {
                if (closeDoor(cnt) != 0) {
                    v2.push_back(i / 2);
                    num++;
                }
                cnt++;
            }
        }
    }
    v.clear();
    cout << cnt << " " << num << "\n";
    cnt = num = 0;
    clearRoom();
    for (auto a: v2) {
        for (int i = a * 2; i < (a + 1) * 2; i++) {
            putIn(i, i);
            if (closeDoor(i) != 0) {
                arrest(i);
            }
        }
    }
    clearRoom();
}

void investigate2() {
//    for (int i = 0; i < 10; i++) {
//        putIn(i, i);
//        if (closeDoor(i) != 0) {
//            arrest(i);
//        }
//    }
    for (int i = 0; i < MAX_NUM; i++) {
        putIn(i / 1000, i);
    }
    int ncnt = 0, ycnt = 0, room_idx = 0;
    for (int i = 0; i < 1000; i++) {
        if (closeDoor(i) == 1) {
            room[i] = 0;
            for (int j = i * 1000; j < (i + 1) * 1000; j++) {
                putIn(j / 100, j);
            }
            int a = i * 1000 / 100;
            if (closeDoor(a) == 1) {
                room[a] = 0;
                for (int k = a * 100; k < (a + 1) * 100; k++) {
                    putIn(k / 10, k);
                }
                int b = i * 1000 / 10;
                if (closeDoor(b) == 1) {
//                    room[b] = 0;
//                    for (int l = b * 10; l < (b + 1) * 10; l++) {
//                        putIn(l, l);
//                    }
//                    int c = i * 1000;
//                    if(closeDoor(c) == 1) {
//                        ycnt++;
//                    }else ncnt++;
                }
            }
        }
    }
//    for (int j = 0; j < 10000; j++) {
//        if (closeDoor(j) == 1) {
//            room[j] = 0;
//            for (int i = j * 10000; i < (j + 1) * 10000; i++) {
//                putIn(i / 10, i);
//            }
//        }
//    }
//    for (int j = 0; j < 100000; j++) {
//        if (closeDoor(j) == 1) {
//            ycnt++;
//        } else ncnt++;
//    }
    cout << ncnt << " " << ycnt << " " << room_idx << "\n";
}


void putIn(int n, int a) { // 마법의 방에 사람을 넣음 (n: 방 번호, a: 사람 번호)
    if (n < 0 || n >= MAX_NUM) return;
    if (a < 0 || a >= MAX_NUM) return;
    room[n] |= citizen[a];
}

int closeDoor(int n) { // n번 방의 문 색 확인 (return 1 : 범인 있음, return 0 : 범인 없음)
    SCORE += 1;
    if (n < 0 || n >= MAX_NUM) return 0;
    return room[n];
}

void clearRoom() { // 마법의 방이 모두 꽉 찼을 때 사용
    for (int i = 0; i < MAX_NUM; i++) room[i] = 0;
}

void arrest(int a) { // a번 사람을 보안팀에 넘기는 함수
    SCORE += 10;
    if (a < 0 || a >= MAX_NUM) return;
    if (citizen[a] == 0) SCORE += 10000; // 조직원이 아닌 사람을 뽑으면 패널티
    arrested[a] = 1;
}


static unsigned long long seed = 113;
std::random_device rd;
std::mt19937 gen(seed);
std::uniform_int_distribution<int> dis(0, MAX_NUM - 1);

void init() {
    SCORE = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        citizen[i] = 0;
        room[i] = 0;
        arrested[i] = 0;
    }
    int j;
    for (int i = 0; i < MAX_NUM / 1000; i++) {
        j = dis(gen);
        if (citizen[j] == 1) {
            i--;
            continue;
        }
        citizen[j] = 1;
    }
}

int main() {
    int TC;
    TOTAL_SCORE = TOTAL_TIME = 0;
    freopen("input.txt", "r", stdin);
    scanf("%d", &TC);
    for (int t = 1; t <= TC; t++) {
        init();
        investigate();
        for (int i = 0; i < MAX_NUM; i++) if (citizen[i] == 1 && arrested[i] == 0) SCORE += 90000;
        if (SCORE < 86400) printf("#%d 100 %d\n", t, SCORE);
        else printf("#%d 0 0\n", t);
        TOTAL_SCORE += SCORE;
    }
    printf("TOTAL SCORE : %d\n", TOTAL_SCORE);

}