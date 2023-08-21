#include <iostream>
#include <algorithm>

using namespace std;

int w, h;
int map[50][50];
int visited[50][50];

void dfs(int x, int y) {
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    visited[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(int), 0);
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }
        int island = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    island++;
                }
            }
        }
        cout << island << endl;
    }
}