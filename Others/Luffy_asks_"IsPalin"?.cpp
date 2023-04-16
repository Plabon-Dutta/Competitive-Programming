#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int hsh[N][26];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int testcase;
    cin >> testcase;
    while(testcase--) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 26; j++) {
                hsh[i][j] = 0;
            }
        }

        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        for (int i =0 ; i < n; i++) {
            hsh[i + 1][s[i] - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            for (int i = 1; i <= n; i++) {
                hsh[i][j] += hsh[i - 1][j];
            }
        }

        while (q--) {
            int l, r;
            cin >> l >> r;

            int odd = 0;
            for (int i = 0; i < 26; i++) {
                int tmp = hsh[r][i] - hsh[l - 1][i];
                if (tmp % 2) odd++;
            }

            if (odd > 1) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
    }

    return 0;
}
