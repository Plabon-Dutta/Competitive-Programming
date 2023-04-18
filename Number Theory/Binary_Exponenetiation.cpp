#include <bits/stdc++.h>

using namespace std;

long long int binaryExponenetiation(long long int a, long  long int b) {
    if (b == 0) return 1;
    long long int tmp = binaryExponenetiation(a, b / 2);
    if (b & 1) {
        return (a * tmp * tmp);
    }
    else return (tmp * tmp);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    

    return 0;
}
