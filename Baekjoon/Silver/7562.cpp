#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int I, x, y, dx, dy;
        cin >> I;
        cin >> x >> y;
        cin >> dx >> dy;

        int map[300][300] = {0, };
        queue<pair<int, int>> q;

        q.push(make_pair(x, y));
        map[x][y] = 1;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (cx == dx && cy == dy) {
                cout << map[cx][cy] - 1 << endl;
                break;
            }

            int dcx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
            int dcy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
            for (int i = 0; i < 8; i++) {
                int nx = cx + dcx[i];
                int ny = cy + dcy[i];
                if (nx >= 0 && nx < I && ny >= 0 && ny < I && map[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    map[nx][ny] = map[cx][cy] + 1;
                }
            }
        }
    }
    return 0;
}