#include <bits/stdc++.h>

using namespace std;

void Bubble_Sort (vector <int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - (i + 1); j++) {
            if (nums[j] > nums[j + 1]) { // Use '<' for Decending Order
                swap(nums[j], nums[j + 1]);
            }
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

    Bubble_Sort(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
