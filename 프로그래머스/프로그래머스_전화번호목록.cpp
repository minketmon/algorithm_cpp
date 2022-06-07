#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    return true;
}

//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool solution(vector<string> phone_book) {
//    bool answer = true;
//
//    for (int i = 0; i < phone_book.size(); i++) {
//        for (int j = 0; j < phone_book.size(); j++) {
//            if (i == j) continue;
//            if (phone_book[i].length() < phone_book[j].length()) {
//                if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length()))
//                    return false;
//            }
//        }
//    }
//
//    return answer;
//}