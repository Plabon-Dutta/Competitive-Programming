#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> graph[N];
int val[N];
int depth[N];
int sum;

void DFS1(int vertex, int parent = 0) {
    for (auto child : graph[vertex]) {
        if (child == parent) continue;
        depth[child] = depth[vertex] + 1;
        DFS1(child, vertex);
    }
}

void DFS2(int vertex) {
    for (auto child : graph[vertex]) {
        if (depth[child] < depth[vertex]) continue;
        sum += val[child];
        DFS2(child);
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

    DFS1(1);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        sum = val[x];
        DFS2(x);
        cout << sum << '\n';
    }

    return 0;
}
