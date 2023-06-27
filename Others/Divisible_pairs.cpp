#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    map <int, int> mm;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % m == 0) {
            ans += mm[0];
        }
        else {
            ans += (mm[m - (x % m)]);
        }
        mm[x % m]++;
    }

    cout << ans << '\n';

    return 0;
}
