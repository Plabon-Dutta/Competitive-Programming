#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long int binaryExponenetiation(long long int a, long  long int b) {
    if (b == 0) return 1;
    long long int tmp = binaryExponenetiation(a, b / 2);
    if (b & 1) {
        return (a * ((tmp * tmp) % mod)) % mod;
    }
    else return (tmp * tmp) % mod;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    

    return 0;
}
