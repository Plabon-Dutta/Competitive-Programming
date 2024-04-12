#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N];

long long int max_subarray_sum (int n) {
    long long int mx = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        mx += a[i];

        ans = max(ans, mx);

        if (mx < 0) mx = 0;
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

// Kadane’s algorithm
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
