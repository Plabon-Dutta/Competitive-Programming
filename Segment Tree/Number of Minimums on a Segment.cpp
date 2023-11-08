#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];
vector <pair <long long int, int>> sum(4 * N);

void build (int node, int b, int e) {
    if (b == e) {
        sum[node].first = a[b];
        sum[node].second = 1;
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    build(l, b, mid);
    build(r, mid + 1, e);

    sum[node].first = min(sum[l].first, sum[r].first);

    if (sum[l].first < sum[r].first) {
        sum[node].second = sum[l].second;
    }
    else if (sum[l].first > sum[r].first) {
        sum[node].second = sum[r].second;
    }
    else {
        sum[node].second = sum[l].second + sum[r].second;
    }
}

pair <long long int, int> query (int node, int b, int e, int i, int j) {
    if (b > j || e < i) {
        pair <long long int, int> tmp = {INT_MAX, 0};
        return tmp;
    }

    if (b >= i && e <= j) {
        return sum[node];
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    pair <long long int, int> left = query(l, b, mid, i, j);
    pair <long long int, int> right = query(r, mid + 1, e, i, j);

    pair <long long int, int> tmp;
    tmp.first = min(left.first, right.first);

    if (left.first < right.first) {
        tmp.second = left.second;
    }
    else if (left.first > right.first) {
        tmp.second = right.second;
    }
    else {
        tmp.second = left.second + right.second;
    }

    return tmp;
}

void update (int node, int b, int e, int i, int val) {
    if (b > i || e < i) {
        return;
    }

    if (b == i && e == i) {
        sum[node].first = val;
        sum[node].second = 1;
        return;
    }

    int l = (2 * node), r = ((2 * node) + 1);
    int mid = (b + e) / 2;

    update(l, b, mid, i, val);
    update(r, mid + 1, e, i, val);

    sum[node].first = min(sum[l].first, sum[r].first);

    if (sum[l].first < sum[r].first) {
        sum[node].second = sum[l].second;
    }
    else if (sum[l].first > sum[r].first) {
        sum[node].second = sum[r].second;
    }
    else {
        sum[node].second = sum[l].second + sum[r].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int x;
        cin >> x;

        if (x == 1) {
            int i, v;
            cin >> i >> v;

            update(1, 1, n, i + 1, v);
        }
        else {
            int l, r;
            cin >> l >> r;

            pair <long long int, int> tmp = query(1, 1, n, l + 1, r); 

            cout << tmp.first << ' ' << tmp.second << '\n';
        }
    }
    
    return 0;
}
