#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N, K;
int visited[100001];
int parent[100001];

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) {
            cout << visited[cur] - 1 << '\n';
            stack<int> s;
            while (cur != start) {
                s.push(cur);
                cur = parent[cur];
            }
            s.push(start);
            while (!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            }
            return;
        }
        if (cur - 1 >= 0 && !visited[cur - 1]) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
            parent[cur - 1] = cur;
        }
        if (cur + 1 <= 100000 && !visited[cur + 1]) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
            parent[cur + 1] = cur;
        }
        if (cur * 2 <= 100000 && !visited[cur * 2]) {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
            parent[cur * 2] = cur;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    bfs(N, K);
    return 0;
}