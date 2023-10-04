#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> tree[100001]; // {node, weight}
int dist[100001]; // distance from root
bool visited[100001];

int bfs(int start) {
    int max_dist = 0;
    int max_node = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i].first;
            int weight = tree[node][i].second;
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[node] + weight;
                q.push(next);
                if (max_dist < dist[next]) {
                    max_dist = dist[next];
                    max_node = next;
                }
            }
        }
    }
    return max_node;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }

    // find the farthest node from node 1
    int max_node = bfs(1); // start from node 1
    for (int i = 1; i <= n; i++) { // reset
        dist[i] = 0;
        visited[i] = false;
    }
    // find the farthest node from max_node
    max_node = bfs(max_node); // start from max_node
    cout << dist[max_node] << '\n';
    return 0;
}
