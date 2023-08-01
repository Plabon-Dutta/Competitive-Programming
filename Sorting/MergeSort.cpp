#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N];

void merge(int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int id = l;

    int b[r + 1];
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[id] = a[i];
            i++;
        }
        else {
            b[id] = a[j];
            j++;
        }

        id++;
    }

    if (i > mid) {
        while (j <= r) {
            b[id] = a[j];
            j++;
            id++;
        }
    }
    else {
        while (i <= mid) {
            b[id] = a[i];
            i++;
            id++;
        }
    }

    for (int i = l; i <= r; i++) {
        a[i] = b[i];
    }
}

void mergesort(int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n = 10;

    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';

    mergesort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
