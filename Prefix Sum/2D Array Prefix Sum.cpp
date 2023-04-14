#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n + 1][m + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int pre[n + 1][m + 1];
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            cout << pre[i][j] << " \n"[j == m];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}
