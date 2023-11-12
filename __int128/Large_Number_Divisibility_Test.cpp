#include <bits/stdc++.h>

using namespace std;

std::ostream& operator << (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value<0?-value:value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            -- d;
            *d = "0123456789"[tmp%10];
            tmp/=10;
        }while(tmp!=0);
        if(value<0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer)-d;
        if (dest.rdbuf()->sputn(d,len)!=len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int val(char c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

__int128 convert (string a, int c) {
    __int128 N = 0, x = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        N += val(a[i]) * x;
        x *= c;
    }
    
    return N;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    string a, b;
    int c;

    while (cin >> a >> b >> c) {
        __int128 A = convert(a, c);
        __int128 B = convert(b, c);
        
        // cout << A << ' ' << B << '\n';
        
        if (A % B == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
