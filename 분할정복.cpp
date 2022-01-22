int A[MAXN + 10];
int sorted[MAXN + 10];

void merge(int l, int m, int r) {
    int i, j, k;
    i = l; j = m + 1; k = l;
    while (i <= m && j <= r) {
        if (A[i] <= A[j])
            sorted[k++] = A[i++];
        else
            sorted[k++] = A[j++];
    }

    // 남아있는 값들 일괄 복사
    if (i > m) {
        while (j <= r)
            sorted[k++] = A[j++];
    }
    else {
        while (i <= m)
            sorted[k++] = A[i++];
    }

    // 배열 복사
    for (i = l; i <= r; i++)
        A[i] = sorted[i];
}

void mergeSort(int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void qsort(int l, int r) {
    int s=l; int e=r;
    int pivot = arr[(l+r)/2];

    if(l >= r) return;

    while(s <= e){
        while(arr[s] > pivot) s++;
        while(arr[e] < pivot) e--;
        if(s <= e){
            int temp;
            temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++; e--;
        }
    }
    qsort(l,e);
    qsort(s,r);
}

int binarySearch(int arr[], int s, int e, int target) {
    while (s <= e) {
        int m = (s + e) / 2;

        if (arr[m] == target) return m;
        else if (arr[m] < target) s = m + 1;
        else e = m - 1;
    }

    return -1;
}