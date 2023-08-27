#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N;
int box[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        visited[cx][cy] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (box[nx][ny] == 0 && visited[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    box[nx][ny] = box[cx][cy] + 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) { // 토마토 상자 입력
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    int max = 0;
    int flag = 0;

    for (int i = 0; i < N; i++) { // 토마토 상자 출력
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                flag = 1;
            }
            if (max < box[i][j]) {
                max = box[i][j];
            }
        }
    }

    if (flag == 1) {
        cout << -1 << endl;
    } else {
        cout << max - 1 << endl;
    }

    return 0;
}