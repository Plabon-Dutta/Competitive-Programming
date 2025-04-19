#include <bits/stdc++.h>

using namespace std;

void Selection_Sort (vector <int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[mn]) { // Use '>' for Decending Order
                mn = j;
            }
        }

        if (mn != i) {
            swap(nums[i], nums[mn]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Selection_Sort(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
