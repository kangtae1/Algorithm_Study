#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<string> board;
vector<vector<bool>> visited;
vector<vector<bool>> check;

int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};

bool dfs(int x, int y, int cnt, char color) {
    visited[x][y] = true;
    if (cnt == 1) {
        check[x][y] = true;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] != color) continue;
        if (cnt >= 4 && check[nx][ny]) return true;
        if (visited[nx][ny]) continue;

        if (dfs(nx, ny, cnt + 1, color)) return true;
    }

    check[x][y] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board.resize(N);
    visited.resize(N, vector<bool>(M, false));
    check.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    bool flag = false;

    for (int i = 0; i < N && !flag; i++) {
        for (int j = 0; j < M && !flag; j++) {
            fill(visited.begin(), visited.end(), vector<bool>(M, false));
            fill(check.begin(), check.end(), vector<bool>(M, false));
            flag = dfs(i, j, 1, board[i][j]);
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}