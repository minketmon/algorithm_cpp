#include <iostream>
#include <cstring>

using namespace std;
int n, arr[100001], cpy[100001];
long long ans;

void merge(int left, int mid, int right) {
    int ptr1 = left, ptr2 = mid, idx = 0;
    while (ptr1 < mid && ptr2 < right) {
        if (arr[ptr1] < arr[ptr2]) cpy[idx++] = arr[ptr1++];
        else {
            if (arr[ptr1] > arr[ptr2]) ans += mid - ptr1;
            cpy[idx++] = arr[ptr2++];
        }
    }
    while (ptr1 < mid) cpy[idx++] = arr[ptr1++];
    while (ptr2 < right) cpy[idx++] = arr[ptr2++];
    for (int i = 0; i < right - left; i++) arr[i + left] = cpy[i];
}

void merge_sort(int left, int right) {
    int mid = (left + right) / 2;
    if (left >= right) return;
    if (left < mid) {
        merge_sort(left, mid);
        merge_sort(mid, right);
        merge(left, mid, right);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int tc, t;
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(cpy, 0, sizeof(cpy));
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        merge_sort(0, n);
        cout << '#' << tc << ' ' << ans << '\n';
    }
}