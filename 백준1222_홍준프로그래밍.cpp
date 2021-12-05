#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long arr[2000001];
long long cnt[2000001];
vector<int> v;

//void check(long long num) {
//    for (int i = 1; i * i <= num; i++) {
//        if (num % i == 0) { // 약수이면
//            if (i != num / i) {
//                arr[i] += i;
//                cnt[i]++;
//                arr[num / i] += num / i;
//                cnt[num / i]++;
//            } else {
//                arr[i] += i;
//                cnt[i]++;
//            }
//        }
//    }
//}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    long long max_num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        //check(num);
        arr[num]++;
    }
    for(int i=1; i<=2000000; i++) {
        for(int j=i; j<=2000000; j+=i) {
            if(arr[j]) {
                cnt[i]+= arr[j];
            }
        }
    }
    for(int i=1; i<=2000000; i++) {
        if(cnt[i]>1) {
            max_num = max(max_num, i*cnt[i]);
        }
    }
    cout << max_num;
}
