#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> graph[N];
int val[N];
int subtreeSum[N];
int depth[N];

void DFS(int vertex, int parent = 0) {
    subtreeSum[vertex] += val[vertex];
    for (auto child : graph[vertex]) {
        if (child == parent) continue;
        DFS(child, vertex);
        subtreeSum[vertex] += subtreeSum[child];
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int v;
    cin >> v;

    for (int i = 1; i <= v; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < v - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    } 

    DFS(1);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << subtreeSum[x] << '\n';
    }

    return 0;
}
