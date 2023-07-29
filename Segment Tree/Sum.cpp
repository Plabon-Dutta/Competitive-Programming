#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];
int tree[N * 3];

void make(int node, int l, int r) {
    if (l == r) {
     tree[node] = arr[l];
     return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;

    make(left, l, mid);
    make(right, mid + 1, r);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int i, int j) {
    if (i > r || j < l) {
     return 0;
    }

    if (i >= l && j <= r) {
     return tree[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;

    int sum1 = query(left, l, mid, i, j);
    int sum2 = query(right, mid + 1, r, i, j);

    return sum1 + sum2;
}

void update(int node, int l, int r, int i, int val) {
    if (i > r || i < l) {
        return;
    }

    if (l >= i && i <= r) {
        tree[node] = val;
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;

    update(left, l, mid, i, val);
    update(right, mid + 1, r, i, val);

    tree[node] = tree[left] + tree[right];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    make(1, 1, n);

    while (q--) {
        int x;
        cin >> x;

        if (x == 1) {
            int id, val;
            cin >> id >> val;

            update(1, 1, n, id, val);
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}
