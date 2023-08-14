#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int testcase;
    cin >> testcase;
    
    while(testcase--) {
        int n, ans = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int p[n + 1];
            for (int j = 1; j < i; j++) {
                p[j] = j;
            }
            for (int j = i; j <= n; j++) {
                p[j] = (n - (j - i));
            }

            int s = 0, mx = 0;
            for (int j = 1; j <= n; j++) {
                s += (p[j] * j);
                mx = max(mx, (p[j] * j));
            }

            ans = max(ans, s - mx);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
