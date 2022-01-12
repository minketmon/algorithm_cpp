#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int par[201][2], bubu[201], cnt, chon[201][201];
bool gender[201];
vector<int> child[201];
map<string, int> m;


void init(char initialMemberName[], int initialMemberSex) {
    memset(par, -1, sizeof(par));
    memset(bubu, -1, sizeof(bubu));
    memset(chon, 0, sizeof(chon));
    m.clear();
    for (int i = 0; i < cnt; i++) child[i].clear();
    cnt = 0;

    gender[0] = initialMemberSex;
    m.insert({initialMemberName, 0});
    cnt++;
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[]) {
    int ex = m.find(existingMemberName)->second;
    bool flag = false;

    if (relationship == 0) {
        if (newMemberSex != gender[ex] && bubu[ex] == -1) {
            flag = true;
            bubu[ex] = cnt;
            bubu[cnt] = ex;
            child[cnt] = child[ex];
            for (int i: child[ex]) {
                par[i][newMemberSex] = cnt;
            }
            for (int i = 0; i < cnt; i++) {
                chon[cnt][i] = chon[ex][i];
                chon[i][cnt] = chon[cnt][i];
            }
        }
    } else if (relationship == 1) {
        if (par[ex][newMemberSex] == -1) {
            flag = true;
            if (par[ex][!newMemberSex] != -1) {
                int tmp = par[ex][!newMemberSex]; // 기존 구성원의 새 구성원과 성별이 다른 부모
                bubu[tmp] = cnt;
                bubu[cnt] = tmp;
                for (int i: child[tmp]) {
                    par[i][newMemberSex] = cnt;
                    child[cnt].push_back(i);
                }
                for (int i = 0; i < cnt; i++) {
                    chon[cnt][i] = chon[tmp][i];
                    chon[i][cnt] = chon[tmp][i];
                }
            } else {
                par[ex][newMemberSex] = cnt;
                child[cnt].push_back(ex);
                for (int i = 0; i < cnt; i++) {
                    chon[cnt][i] = chon[ex][i] + 1;
                    chon[i][cnt] = chon[cnt][i];
                }
            }
        }
    } else if (relationship == 2) {
        flag = true;
        par[cnt][gender[ex]] = ex;
        child[ex].push_back(cnt);
        if (bubu[ex] != -1) {
            int tmp = bubu[ex];
            par[cnt][gender[tmp]] = tmp;
            child[tmp].push_back(cnt);
        }
        for (int i = 0; i < cnt; i++) {
            chon[cnt][i] = chon[ex][i] + 1;
            chon[i][cnt] = chon[cnt][i];
        }
    }
    if (flag) {
        m.insert({newMemberName, cnt});
        gender[cnt] = newMemberSex;
        cnt++;
    }
    return flag;
}

int getDistance(char nameA[], char nameB[]) {
    int a = m.find(nameA)->second;
    int b = m.find(nameB)->second;
    return chon[a][b];
}

int countMember(char name[], int dist) {
    int x = m.find(name)->second;
    int c = 0;
    for (int i = 0; i < cnt; i++) {
        if (i != x && chon[x][i] == dist) c++;
    }
    return c;
}