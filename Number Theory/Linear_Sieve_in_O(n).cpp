    #include <bits/stdc++.h>
    using namespace std;

    const int N = 10000000;
    vector<int> spf(N+1);
    vector<int> prime;

    void calculate() {
        for (int i=2; i <= N; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                prime.push_back(i);
            }
            for (int j = 0; i * prime[j] <= N; ++j) {
                spf[i * prime[j]] = prime[j];
                if (prime[j] == spf[i]) {
                    break;
                }
            }
        }
    }


    int main() {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        
        calculate();

        int testcase;
        cin >> testcase;
        while(testcase--) {
            int n;
            cin >> n;

            cout << spf[n] << '\n'; // just showing spf
        }
        
        return 0;
    }

    // Find primes and Smallest Prime Factor of any number less than 1e7 in O(n) 
