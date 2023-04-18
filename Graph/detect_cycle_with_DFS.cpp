#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> graph[N];
bool visited[N];

bool DFS(int vertex, int parent) {
    visited[vertex] = true;
    bool cycle = false;
    for (auto child : graph[vertex]) {
        if (!visited[child]) {
            cycle |= DFS(child, vertex);
        }
        else if (visited[child] && child != parent) cycle = true;
    }
    return cycle;
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

    bool flag = false;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (DFS(i, 0)) {
                flag = true;
            }
        }
    }

    if (flag) cout << "Cycle Exists!" << '\n';
    else cout << "Cycle don't Exist!" << '\n';

    return 0;
}
