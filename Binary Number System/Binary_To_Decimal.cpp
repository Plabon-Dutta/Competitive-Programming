#include <bits/stdc++.h>

using namespace std;

void getDecimal (int n) {
    int pow = 1;
    int ans = 0;

    while (n) {
        int rem = n % 10;
        n /= 10;

        ans += (rem * pow);

        pow *= 2;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    getDecimal(101);
    
    return 0;
}
