#include <bits/stdc++.h>

using namespace std;

void getBinary (int n) {
    int pow = 1;
    int ans = 0;

    while (n) {
        int rem = n % 2;
        n /= 2;

        ans += (rem * pow);

        pow *= 10;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    getBinary(12);
    
    return 0;
}
