#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[100001];
int ans[100001];
bool visited[100001];

bool comp(int a, int b) {
    return ans[a] < ans[b];
}

bool bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int idx = 2;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: graph[cur]) {
            if (visited[next]) {
                continue;
            } else if (!visited[next] && ans[next] == idx) {
                visited[next] = true;
                idx++;
                q.push(next);
            } else if (ans[next] != idx) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ans[x] = i + 1;
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), comp);
    }

    cout << (bfs() ? 1 : 0) << '\n';

    return 0;
}