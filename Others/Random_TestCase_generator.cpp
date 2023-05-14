#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline long long int gen_random(long long int l, long long int r) {
    return uniform_int_distribution<long long int>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n = gen_random(1, 1000);
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << gen_random(1, 100) << ' ';
    }

    return 0;
}
