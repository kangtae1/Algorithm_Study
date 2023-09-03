#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> graph[3001];
int dist[3001];
int cycle[3001];
bool visited[3001];

// 순환선 찾기
int dfs(int node, int prev) {
    if (visited[node]) {
        return node;
    }
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (next == prev) {
            continue;
        }

        int ret = dfs(next, node);
        if (ret == -2) {
            return -2;
        }
        if (ret >= 0) {
            cycle[node] = true;
            if (node == ret) {
                return -2;
            } else {
                return ret;
            }
        }
    }
    return -1;
}

// 거리 재기
void bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (cycle[i]) {
            dist[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (cycle[next]) {
                continue;
            }

            if (dist[next] == -1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(dist, dist + 3001, -1);
    dfs(1, -1);
    bfs();

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}