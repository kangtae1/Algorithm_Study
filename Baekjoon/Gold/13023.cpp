#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, int depth, int& answer) {
    if (depth == 4) {
        answer = 1;
        return;
    }

    visited[cur] = true;

    for (int next : graph[cur]) {
        if (visited[next]) continue;

        dfs(graph, visited, next, depth + 1, answer);

        if (answer == 1) return;
    }

    visited[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        dfs(graph, visited, i, 0, answer);

        if (answer == 1) break;
    }

    cout << answer << endl;

    return 0;
}