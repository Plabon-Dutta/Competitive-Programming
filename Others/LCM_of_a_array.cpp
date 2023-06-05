#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int N = 1e6 + 7;
vector <int> prime;
bool pchk[N];


void sieve() {
    prime.push_back(2);
    pchk[0] = pchk[1] = true;
    for(int i = 4; i < N; i += 2) {
        pchk[i] = true;
    }
    for(int i = 3; i * i < N; i += 2) {
        if(!pchk[i]) {
            for(int j = i + i; j < N; j += i) {
                pchk[j] =  true;
            }
        }
    }
    for(int i = 3; i < N; i += 2) {
        if(!pchk[i]) {
            prime.push_back(i);
        }
    }
    sort(prime.begin(), prime.end());
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    sieve();
    int n;
    cin >> n;

    // Normal Way But will generate Wrong Answer
    int ans = 1;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        ans = ((ans * a[i]) / __gcd(ans, a[i])) % mod;
    }

    cout << ans << '\n';

    // Optimize way that generate Correct Answer
    ans = 1;

    map <int, int> mm;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 0; prime[j] <= x; j++) {
            if (x % prime[j] == 0) {
                int c = 0;
                while (x % prime[j] == 0) {
                    x /= prime[j];
                    c++;
                }
                mm[prime[j]] = max(mm[prime[j]], c);
            }
        }
    }

    for (auto i : mm) {
        ans = (ans * (long long int)pow(i.first, i.second)) % mod;
    }

    cout << ans << '\n';

    return 0;
}
