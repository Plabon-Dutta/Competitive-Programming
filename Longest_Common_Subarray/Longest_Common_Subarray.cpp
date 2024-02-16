#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    map <int, int> mm;
    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, mm[a[i]]);

        ans = max(ans, i - j + 1);

        mm[a[i]] = i + 1;
    }

    cout << ans << '\n';

    return 0;
}

// https://cses.fi/problemset/task/1141
