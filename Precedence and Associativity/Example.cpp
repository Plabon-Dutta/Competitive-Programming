#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int a = 5, b = 3, c = 4;

    cout << a + b * c << '\n';  // multiplication has higher higher precedence than addition
    cout << (a + b) * c << '\n';    // parentheses goes first
    cout << a - b + c << '\n';  // same precedence so follow left to right rule (left associativity)
    cout << (a << b + c) << '\n';   // addition has higher precedence than left shift
    cout << (a * b / c) << '\n';    // same precedence so follow left to right rule (left associativity)
    cout << (a / b * c) << '\n';    // same precedence so follow left to right rule (left associativity)
    cout << (a | b & c) << '\n';    // bitwise and has higher precedence than bitwise or
    cout << (a ^ b | c) << '\n';    // bitwise xor has higher precedence than bitwise or
    cout << (a ^ b & c) << '\n';    // bitwise and has higher precedence than bitwise xor
    cout << (a + b == c) << '\n';   // addition has higher precedence than comparison
    cout << (a & b == 3) << '\n';   // comparison has higher precedence than bitwise and

    return 0;
}
