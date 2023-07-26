// Check Prime Till 1e18 in almost 0 Seconds
long long int binpower(long long int base, long long int e, long long int mod) {
    long long int result = 1;
    base %= mod;
    while (e) {
        if (e & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(long long int n, long long int a, long long int d, long long int s) {
    long long int x = binpower(a, d, n);
    if (x == 1 || x == n - 1) {
        return false;
    }
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1){
            return false;
        }
    }
    return true;
};

bool RabinMiller(long long int n, long long int iter = 5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    long long int s = 0;
    long long int d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        long long int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s)) {
            return false;
        }
    }
    return true;
}
