#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> tmp;
vector <vector <int>> connected_component;
vector <int> graph[N];
bool visited[N];

void DFS(int v) {
    visited[v] = true;
    tmp.push_back(v);
    for (auto child : graph[v]) {
        if (!visited[child]) {
            DFS(child);
        }
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

    int ans = 0;
    for (int i = 1; i <= v; i++) {

        if (!visited[i]) {
            DFS(i);
            ans++;
            connected_component.push_back(tmp);
            tmp.clear();
        }
    }
    cout << ans << '\n';
    for (auto i : connected_component) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
