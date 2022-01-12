#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int quan[200001], _min[10], _gap[10];
priority_queue<pair<int, pair<int, int>>> buys[10], sells[10];
bool is_cancel[200001];

void init() {
    memset(_min, -1, sizeof(_min));
    memset(_gap, 0, sizeof(_gap));
    memset(is_cancel, 0, sizeof(is_cancel));
    for (int i = 0; i < 10; i++) {
        if (!sells[i].empty()) {
            while (!sells[i].empty()) {
                sells[i].pop();
            }
        }
        if (!buys[i].empty()) {
            while (!buys[i].empty()) {
                buys[i].pop();
            }
        }
    }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice) {
    if (sells[mStock].size() == 0) {
        buys[mStock].push({mPrice, {-mNumber, mQuantity}});
        quan[mNumber] = mQuantity;
        return mQuantity;
    } else {
        while (!sells[mStock].empty()) {
            int Num = -sells[mStock].top().second.first;
            int Quan = quan[Num];
            int Pri = -sells[mStock].top().first;
            if (mQuantity == 0) break;
            if (mPrice < Pri) {
                break;
            }
            sells[mStock].pop();
            if (is_cancel[Num]) continue;
            if (Quan < mQuantity) {
                mQuantity -= Quan;
                Quan = 0;
                if(_min[mStock] > 0){
                    _min[mStock] = min(Pri, _min[mStock]);
                    int g = Pri - _min[mStock];
                    _gap[mStock] = max(g, _gap[mStock]);
                }
                else _min[mStock] = Pri;
            } else {
                Quan -= mQuantity;
                mQuantity = 0;
                if(_min[mStock] > 0){
                    _min[mStock] = min(Pri, _min[mStock]);
                    int g = Pri - _min[mStock];
                    _gap[mStock] = max(g, _gap[mStock]);
                }
                else _min[mStock] = Pri;
            }
            if (Quan > 0) {
                quan[Num] = Quan;
                sells[mStock].push({-Pri, {-Num, Quan}});
            }
        }
        if (mQuantity > 0) {
            buys[mStock].push({mPrice, {-mNumber, mQuantity}});
            quan[mNumber] = mQuantity;
            return mQuantity;
        }
    }
    return 0;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice) {
    if (buys[mStock].size() == 0) {
        sells[mStock].push({-mPrice, {-mNumber, mQuantity}});
        quan[mNumber] = mQuantity;
        return mQuantity;
    } else {
        while (!buys[mStock].empty()) {
            int Num = -buys[mStock].top().second.first;
            int Quan = quan[Num];
            int Pri = buys[mStock].top().first;
            if (mQuantity == 0) break;
            if (mPrice > Pri) {
                break;
            }
            buys[mStock].pop();
            if (is_cancel[Num]) continue;
            if (Quan < mQuantity) {
                mQuantity -= Quan;
                Quan = 0;
                if(_min[mStock] > 0) {
                    _min[mStock] = min(Pri, _min[mStock]);
                    int g = Pri - _min[mStock];
                    _gap[mStock] = max(g, _gap[mStock]);
                }
                else _min[mStock] = Pri;
            } else {
                Quan -= mQuantity;
                mQuantity = 0;
                if(_min[mStock] > 0){
                    _min[mStock] = min(Pri, _min[mStock]);
                    int g = Pri - _min[mStock];
                    _gap[mStock] = max(g, _gap[mStock]);
                }
                else _min[mStock] = Pri;
            }
            if (Quan > 0) {
                quan[Num] = Quan;
                buys[mStock].push({Pri, {-Num, Quan}});
            }
        }
        if (mQuantity > 0) {
            sells[mStock].push({-mPrice, {-mNumber, mQuantity}});
            quan[mNumber] = mQuantity;
            return mQuantity;
        }
    }
    return 0;
}

void cancel(int mNumber) {
    is_cancel[mNumber] = true;
}

int bestProfit(int mStock) {
    return _gap[mStock];
}