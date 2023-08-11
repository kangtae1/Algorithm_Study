#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    visited[cur] = true;

    cout << cur << ' ';

    for (int next : graph[cur]) {
        if (visited[next]) continue;

        dfs(graph, visited, next);
    }
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : graph[cur]) {
            if (visited[next]) continue;

            q.push(next);
            visited[next] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited, V);

    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    cout << '\n';

    bfs(graph, visited, V);

    return 0;
}