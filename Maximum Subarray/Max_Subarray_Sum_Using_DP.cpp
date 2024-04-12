#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N];

long long int max_subarray_sum (int n) {
    long long int dp[n], ans = a[0];
    dp[0] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(1LL * a[i], a[i] + dp[i - 1]);

        ans = max(ans, dp[i]);
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

    cout << max_subarray_sum(n) << '\n';
    
    return 0;
}
