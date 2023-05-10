#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
vector <int> prime_divisor[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int i = 2; i < N; i++) {
        if (prime_divisor[i].empty()) {
            for (int j = i; j < N; j += i) {
                prime_divisor[j].push_back(i);
            }
        }
    }

    int n;
    cin >> n;

    for (auto i : prime_divisor[n]) {
        cout << i << ' ';
    }

    return 0;
}
