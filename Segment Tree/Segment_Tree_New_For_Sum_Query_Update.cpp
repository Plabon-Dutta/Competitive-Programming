#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];
int sum[4 * N];

void build (int node, int b, int e) {
    if (b == e) {
        sum[node] = a[b];
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    build(l, b, mid);
    build(r, mid + 1, e);

    sum[node] = sum[l] + sum[r];
}

int query (int node, int b, int e, int i, int j) {
    if (b > j || e < i) {
        return 0;
    }

    if (b >= i && e <= j) {
        return sum[node];
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void update (int node, int b, int e, int i, int val) {
    if (b > i || e < i) {
        return;
    }

    if (b == i && e == i) {
        sum[node] = val;
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    update(l, b, mid, i, val);
    update(r, mid + 1, e, i, val);

    sum[node] = sum[l] + sum[r];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    cout << query(1, 1, n, 2, 4) << '\n';

    update(1, 1, n, 3, 5);

    cout << query(1, 1, n, 2, 4) << '\n';
    
    return 0;
}
