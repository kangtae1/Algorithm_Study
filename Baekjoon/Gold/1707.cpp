#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int K, V, E;
vector<int> graph[20001];
int visited[20001];

void dfs(int node, int color) {
    visited[node] = color;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next] == 0) {
            dfs(next, 3 - color);
        }
    }
}

void bfs(int node, int color) {
    visited[node] = color;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next] == 0) {
                visited[next] = 3 - visited[cur];
                q.push(next);
            }
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    while (K--) {
        cin >> V >> E;
        for (int i = 1; i <= V; i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                dfs(i, 1);
            }
        }

        if (isBipartiteGraph()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}