#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int S;
int visited[1001][1001];

int bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1][0] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int clip = q.front().second;
        q.pop();

        if (cur == S) return visited[cur][clip] - 1;

        if (cur > 0 && cur < 1001) {
            if (!visited[cur][cur]) {
                visited[cur][cur] = visited[cur][clip] + 1;
                q.push({cur, cur});
            }
            if (clip > 0 && cur + clip < 1001) {
                if (!visited[cur + clip][clip]) {
                    visited[cur + clip][clip] = visited[cur][clip] + 1;
                    q.push({cur + clip, clip});
                }
            }
            if (cur - 1 > 0 && !visited[cur - 1][clip]) {
                visited[cur - 1][clip] = visited[cur][clip] + 1;
                q.push({cur - 1, clip});
            }
        }
    }
}

int main() {
    cin >> S;
    cout << bfs() << endl;
    return 0;
}