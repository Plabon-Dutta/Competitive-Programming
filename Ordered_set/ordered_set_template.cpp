#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

// use one of them by your needs
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // Ascending set & gives count of numbers less than X
// template <typename T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>; // Decending set & gives count of numbers greater than X
// template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // Works like a multiset & gives count of numbers less than X but has erase problem
// template <typename T> using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // Works like a multiset & gives count of numbers greater than X but has erase problem

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    ordered_set <int> s;

    for (int i = 1; i < 10; i++) {
        s.insert(i * 2);
    }

    for (auto i : s) {
        cout << i << ' ';
    }
    cout << '\n';


    cout << s.order_of_key(6) << '\n';
    cout << *s.find_by_order(2) << '\n';

    s.erase(*s.find_by_order(2));
    cout << s.order_of_key(6) << '\n';
    
    return 0;
}
