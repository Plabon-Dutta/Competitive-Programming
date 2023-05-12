#include <bits/stdc++.h>

using namespace std;

long long int solve(long long int n) {
    if (n <= 1) return n;
    long long int p = floor(log2(n)); 
    return ((1LL << (p - 1)) * p) + (n - (1LL << p) + 1) + solve(n - (1LL << p));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long int n;
    cin >> n;

    cout << solve(n) << '\n';

    return 0;
}
