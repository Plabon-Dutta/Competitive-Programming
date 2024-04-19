#include <bits/stdc++.h>

using namespace std;
 
int lcs(string s, string t, int n, int m) { 
    if (n == 0 || m == 0) {
        return 0; 
    }
    if (s[n - 1] == t[m - 1]) {
        return 1 + lcs(s, t, n - 1, m - 1); 
    }
    else {
        return max(lcs(s, t, n, m - 1), lcs(s, t, n - 1, m)); 
    }
} 

int main() {

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    int ans = lcs(s, t, n, m);

    cout << ans << '\n';
    
    return 0;
}
