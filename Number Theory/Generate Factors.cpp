const int N = 1e6 + 10;
vector <int> factor[N];
    
void factors () {
    for (int i = 2; i < N; i++) {
        if (factor[i].empty()) {
            for (int j = 2 * i; j < N; j += i) {
                factor[j].push_back(i);
            }
        }
    }
}
