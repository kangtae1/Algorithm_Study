#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 0x7fffffff));

    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];

        if (dist[a][b] > c) {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (dist[i][k] == 0x7FFFFFFF) continue;
            for (int j = 1; j <= N; j++) {
                if (dist[k][j] == 0x7FFFFFFF) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[1][i] <= K) answer++;
    }

    return answer;
}

int main() {
    int N = 5;
    vector<vector<int>> road = {{1, 2, 1},
                                {2, 3, 3},
                                {5, 2, 2},
                                {1, 4, 2},
                                {5, 3, 1},
                                {5, 4, 2}};
    int K = 3;
    int ret = solution(N, road, K);

    printf("%d\n", ret);
}