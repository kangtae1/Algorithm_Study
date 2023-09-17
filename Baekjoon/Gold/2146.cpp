#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100;

int N;
int map[MAX][MAX];
int island[MAX][MAX];
int min_dist = MAX * MAX;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y, int label) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    island[x][y] = label;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] == 0 || island[nx][ny] != 0) continue;

            q.push(make_pair(nx, ny));
            island[nx][ny] = label;
        }
    }
}

void bfs2(int x, int y, int label) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    int dist = 0;
    bool visited[MAX][MAX] = {false,};
    visited[x][y] = true;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            if (island[cur_x][cur_y] != 0 && island[cur_x][cur_y] != label) {
                min_dist = min(min_dist, dist);
                return;
            }

            for (int j = 0; j < 4; j++) {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;

                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
        dist++;
    }

    return;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int label = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && island[i][j] == 0) {
                bfs(i, j, label++);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                bfs2(i, j, island[i][j]);
            }
        }
    }

    if (min_dist == MAX * MAX)
        cout << "0" << endl;
    else
        cout << min_dist - 1 << endl;

    return 0;
}
