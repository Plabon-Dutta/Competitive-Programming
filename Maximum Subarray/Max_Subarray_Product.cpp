#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N];

long long int max_subarray_product (int n) {
    long long int mx, mn, ans;
    mx = mn = ans = a[0];

    for (int i = 1; i < n; i++) {
        long long int tmp = max({1LL * a[i], a[i] * mx, a[i] * mn});
        mn = max({1LL * a[i], a[i] * mx, a[i] * mn});
        mx = tmp;

        ans = max(ans, mx);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << max_subarray_product(n) << '\n';
    
    return 0;
}
