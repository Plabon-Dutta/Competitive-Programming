#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> graph[N];
int height[N];
int depth[N];

void DFS(int vertex, int parent) {
    for (auto child : graph[vertex]) {
        if (child == parent) continue;
        depth[child] = depth[vertex] + 1;
        DFS(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    } 

    DFS(1, 0);

    for (int i = 1; i <= v; i++) {
        cout << "Node " << i << " : Height - " << height[i] << " Depth - " << depth[i] << '\n';
    }

    return 0;
}
