#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int map[101][101];
int visited[101][101];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // 범위를 벗어나면 무시
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;

            // 벽이면 무시
            if (map[nextX][nextY] == 0) continue;

            // 방문하지 않았으면 방문
            if (visited[nextX][nextY] == 0) {
                q.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = visited[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // map 입력
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    bfs(0, 0);

    cout << visited[N - 1][M - 1] << endl;

    return 0;
}