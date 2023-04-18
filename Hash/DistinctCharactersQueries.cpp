#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();
    vector <set <int>> v(26);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'].insert(i);
    }

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char ch;
            cin >> p >> ch;
            p--;
            v[s[p] - 'a'].erase(p);
            s[p] = ch;
            v[ch - 'a'].insert(p);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                auto it = v[i].lower_bound(l);
                if (it != v[i].end() && *it <= r) {
                    ans++;
                }
            }
            cout << ans << '\n';
            
        }
    }

    return 0;
}
