#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N], segment[1000], segment_size;

void preprocessing(int n) {
    segment_size = sqrt(n);
    int current = -1;

    for (int i = 0; i < n; i++) {
        if (i % segment_size == 0) {
            current++;
        }
        segment[current] += a[i];
    }
}

void update(int idx, int val) {
    int segment_no = idx / segment_size;
    segment[segment_no] -= a[idx];
    segment[segment_no] += val;
    a[idx] = val;
}

int query(int l, int r) {
    int res = 0;
    while (l < r && l % segment_size != 0) {
        res += a[l];
        l++;
    }
    
    while (l + segment_size <= r) {
        res += segment[l / segment_size];
        l += segment_size;
    }

    while (l <= r) {
        res += a[l];
        l++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    preprocessing(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx, val;
            cin >> idx >> val;

            update(idx - 1, val); //let input will be 1 based so sending index - 1
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << query(l - 1, r - 1) << '\n';
        }   
    }
    
    return 0;
}
