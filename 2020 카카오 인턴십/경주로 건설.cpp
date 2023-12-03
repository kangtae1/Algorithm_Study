#include <string>
#include <vector>
#include <queue>

using namespace std;

enum direction{
    RIGHT = 0,
    LEFT = 1,
    DOWN = 2,
    UP = 3
};

typedef struct Pos {
    int x, y, dir, cost;
} Pos;

typedef struct cmp {
    bool operator()(Pos a, Pos b) {
        return a.cost > b.cost;
    }
} cmp;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = (int)board.size();

    priority_queue<Pos, vector<Pos>, cmp> pq;
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(4, 99999999)));

    for (int i = 0; i < 4; i++) {
        cost[0][0][i] = 0;
    }
    pq.push({0, 0, RIGHT, 0});
    pq.push({0, 0, DOWN, 0});

    while (!pq.empty()) {
        Pos pos = pq.top();
        pq.pop();

        if (pos.x == n - 1 && pos.y == n - 1) {
            answer = pos.cost;
            break;
        }

        for (auto i: {RIGHT, LEFT, DOWN, UP}) {
            int nx = pos.x + dx[i];
            int ny = pos.y + dy[i];
            int ncost = pos.cost;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) continue;

            if (pos.dir == i) {
                ncost += 100;
            } else {
                ncost += 600;
            }

            if (cost[nx][ny][i] >= ncost) {
                cost[nx][ny][i] = ncost;
                pq.push({nx, ny, i, ncost});
            }
        }
    }


    return answer;
}


int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 1},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 0, 1, 0, 0, 0, 1},
                                 {0, 0, 1, 0, 0, 0, 1, 0},
                                 {0, 1, 0, 0, 0, 1, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 0}};

    int ret = solution(board); // 3800

    printf("%d\n", ret);
}