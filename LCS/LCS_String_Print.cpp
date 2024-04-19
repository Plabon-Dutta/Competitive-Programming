#include <bits/stdc++.h>

using namespace std;

void LCS (string s, string t) {
    int n = s.size(), m = t.size();
    int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int idx = dp[n][m];

	char ans[idx + 1];
	ans[idx] = '\0';

	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (s[i - 1] == t[j - 1]) {
			ans[idx - 1] = s[i - 1]; 
			i--;
			j--;
			idx--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int testcase = 1;
    // cin >> testcase;
    
    while (testcase--) {
        string s, t, ans = "";
        cin >> s >> t;
        
        LCS(s, t);
    }

    return 0;
}

