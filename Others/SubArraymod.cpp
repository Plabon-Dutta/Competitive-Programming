#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int s = 0, ans = 0;
    map <int, int> mm;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        s += x;
        ans += mm[s % m];
        mm[s % m]++;
    }
    ans += mm[0];

    cout << ans << '\n';
    
    return 0;
}
