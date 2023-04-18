const int N=1e7 + 7;
vector <int> prime;
bool pchk[N];
int cnt[N];


void sieve() {
    prime.push_back(2);
    pchk[0] = pchk[1] = true;
    for(int i = 4; i < N; i += 2) {
        pchk[i] = true;
    }
    for(int i = 3; i * i < N; i += 2) {
        if(!pchk[i]) {
            for(int j = i + i; j < N; j += i) {
                pchk[j] =  true;
            }
        }
    }
    for(int i = 3; i < N - 1; i += 2) {
        if(!pchk[i]) {
            prime.push_back(i);
        }
    }
    sort(prime.begin(), prime.end());
}
