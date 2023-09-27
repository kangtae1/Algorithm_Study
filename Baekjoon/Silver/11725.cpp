#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> tree(N + 1);
    vector<int> parent(N + 1, 0);
    vector<bool> visited(N + 1, false);

    queue<int> q;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i];
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}
