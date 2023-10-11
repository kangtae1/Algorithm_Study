#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<pair<pair<int, int>, int>> result;

    cin >> N >> M;
    board.resize(N, vector<char>(M, '.'));
    visited.resize(N, vector<bool>(M, false));
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            if (board[i][j] == '.') continue;
            int count = 0;
            vector<pair<int, int>> v;
            v.push_back(make_pair(i, j));

            for (auto k = 1; k <= min(N, M) / 2; k++) {
                bool check = true;
                for (auto l = 0; l < 4; l++) {
                    int x = i + dx[l] * k;
                    int y = j + dy[l] * k;
                    if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '.') {
                        check = false;
                        break;
                    }
                    v.push_back(make_pair(x, y));
                }
                if (!check) break;
                count++;
            }

            if (count == 0) continue;

            result.push_back(make_pair(make_pair(i, j), count));
            for (auto k = 0; k < v.size(); k++) {
                visited[v[k].first][v[k].second] = true;
            }
        }
    }

    bool check = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*' && !visited[i][j]) {
                check = false;
            }
        }
    }

    if (!check) {
        cout << -1 << "\n";
    } else {
        cout << result.size() << "\n";
        for (const auto &info: result) {
            cout << info.first.first + 1 << " " << info.first.second + 1 << " " << info.second << "\n";
        }
    }

    return 0;
}