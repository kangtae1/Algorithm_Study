#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int N, K;
int visited[MAX + 1] = {0,};

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) return visited[cur] - 1;

        if (cur - 1 >= 0 && visited[cur - 1] == 0) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if (cur + 1 <= MAX && visited[cur + 1] == 0) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if (cur * 2 <= MAX && visited[cur * 2] == 0) {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
        }
    }
}

int main() {
    cin >> N >> K;

    cout << bfs(N) << endl;

    return 0;
}