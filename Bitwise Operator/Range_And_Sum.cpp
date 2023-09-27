#define MAX 200005
#define bitscount 32
 
int prefix_count[bitscount][MAX];
void findPrefixCount(int arr[], int n) {
    for (int i = 0; i < bitscount; i++) {
        prefix_count[i][0] = ((arr[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            prefix_count[i][j] = ((arr[j] >> i) & 1);
            prefix_count[i][j] += prefix_count[i][j - 1];
        }
    }
}
 
int rangeAnd(int l, int r) {
    int ans = 0;
    for (int i = 0; i < bitscount; i++) {
        int x;
        if (l == 0) {
            x = prefix_count[i][r];
        }
        else{
            x = prefix_count[i][r] - prefix_count[i][l - 1];
        }
 
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }
 
    return ans;
}
