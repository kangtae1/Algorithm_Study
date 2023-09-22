#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int map[101][101];
int dist[101][101];
int dx[] = {0, 0, -1, 1}; // 상하좌우
int dy[] = {-1, 1, 0, 0};
int INF = INT_MAX;

void dijkstra(int x, int y) {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x, y}});
    dist[x][y] = 0;

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[x][y] < cost) continue; // 이미 더 작은 값이 있으면 무시

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖

            int nextCost = cost + map[nx][ny]; // 벽이면 1, 아니면 0
            if (dist[nx][ny] > nextCost) {
                dist[nx][ny] = nextCost;
                pq.push({-nextCost, {nx, ny}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
            dist[i][j] = INF;
        }
    }
    dijkstra(0, 0);
    cout << dist[N - 1][M - 1] << '\n';
    return 0;
}