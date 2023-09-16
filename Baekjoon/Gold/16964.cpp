#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> graph[100001];
int ans[100001];
int dfs_order[100001];
bool visited[100001];
int idx = 0;

bool cmp(int a, int b) {
    return dfs_order[a] < dfs_order[b];
}

bool dfs(int node) {
    if (ans[idx] != node) {
        return false;
    }
    visited[node] = true;

    idx++;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next]) {
            continue;
        }
        if (!dfs(next)) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        dfs_order[ans[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), cmp);
    }

    cout << (dfs(1) ? 1 : 0) << '\n';

    return 0;
}
