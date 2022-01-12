#include <iostream>
#include <vector>
#include <map>

using namespace std;
int cnt, gender[201];
map<string, int> m;
vector<pair<int, int>> v[201];
//	 The below commented functions are for your reference. If you want
//	 to use it, uncomment these functions.
/*
int mstrcmp(const char a[], const char b[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
	return a[i] - b[i];
}

void mstrcpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
}

int mstrlen(const char a[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i);
	return i;
}
*/

void init(char initialMemberName[], int initialMemberSex) {
    m.insert({initialMemberName, cnt});
    gender[cnt] = initialMemberSex;
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[]) {
    //cout << m.find(existingMemberName)->second << "\\\n";
    if (relationship == 0) { // 배우자
        int existingMemberNum = m.find(existingMemberName)->second;
        if (gender[existingMemberNum] != newMemberSex)
            return false;
        for (auto a: v[existingMemberNum]) {
            if (a.first == 0) return false;
        }
        cnt++;
        m.insert({newMemberName, cnt});
        gender[cnt] = newMemberSex;
        v[existingMemberNum].push_back({relationship, cnt});
        v[cnt].push_back({relationship, existingMemberNum});
        for (auto a: v[existingMemberNum]) {
            if (a.first == 2) {
                v[cnt].push_back({2, a.second});
                v[a.second].push_back({1, cnt});
            }
        }
        return true;
    } //else if (relationship == 1) { // 부모
//        int existingMemberNum = m.find(existingMemberName)->second;
//        bool already_par = false;
//        cnt++;
//        for (auto a: v[existingMemberNum]) {
//            if (a.first == 1) {
//                if (gender[a.second] == newMemberSex) {
//                    cnt--;
//                    return false;
//                } else { // 기존 구성원에게 성별이 다른 부모가 있는 경우
//                    already_par = true;
//                    m.insert({newMemberName, cnt});
//                    gender[cnt] = newMemberSex;
//                    v[a.second].push_back({0, cnt});
//                    v[cnt].push_back({0, a.second});
//                    for (auto b: v[a.second]) {
//                        if (b.first == 2) {
//                            v[cnt].push_back({2, b.second});
//                            v[b.second].push_back({1, cnt});
//                        }
//                    }
//                }
//            }
//        }
//        if (!already_par) {
//            m.insert({newMemberName, cnt});
//            gender[cnt] = newMemberSex;
//            v[cnt].push_back({2, existingMemberNum});
//            v[existingMemberNum].push_back({1, cnt});
//        }
//        return true;
//    } else if (relationship == 2) { // 자식
//        int existingMemberNum = m.find(existingMemberName)->second;
//        bool already_par = false;
//        cnt++;
//        m.insert({newMemberName, cnt});
//        gender[cnt] = newMemberSex;
//        for (auto a: v[existingMemberNum]) {
//            if (a.first == 0) {
//                already_par = true;
//                v[cnt].push_back({1, a.second});
//                v[a.second].push_back({2, cnt});
//                v[existingMemberNum].push_back({2, cnt});
//                v[cnt].push_back({1, existingMemberNum});
//            }
//        }
//        if (!already_par) {
//            v[cnt].push_back({1, existingMemberNum});
//            v[existingMemberNum].push_back({2, cnt});
//        }
//    }
    return false;
}

int getDistance(char nameA[], char nameB[]) {
//    int num = m.find(nameA)->second;
//    cout << "nameA : " << nameA << "\n";
//    for (auto a: v[num]) {
//        cout << a.first << " " << a.second << "\n";
//    }
    return -1;
}

int countMember(char name[], int dist) {
    return -1;
}
