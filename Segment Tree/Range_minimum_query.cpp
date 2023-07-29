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

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int l, int r, int i, int j) {
    if (i > r || j < l) {
        return INT_MAX;
    }

    if (i <= l && j >= r) {
        return tree[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (l + r) / 2;

    int mn1 = query(left, l, mid, i, j);
    int mn2 = query(right, mid + 1, r, i, j);

    return min(mn1, mn2);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int testcase, Case = 1;
    cin >> testcase;
    
    while(testcase--) {
        cout << "Case " << Case++ << ":\n";

        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        make(1, 1, n);

        while (q--) {
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    

    return 0;
}
