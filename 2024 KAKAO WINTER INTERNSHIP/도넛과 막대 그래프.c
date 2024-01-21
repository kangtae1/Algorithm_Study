#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int *solution(int **edges, size_t edges_rows, size_t edges_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *) malloc(sizeof(int) << 2);
    memset(answer, 0, sizeof(int) << 2);

    int edge_io[1000001][2];
    memset(edge_io, 0, sizeof(edge_io));

    for (int edge = 0; edge < edges_rows; edge++) {
        edge_io[edges[edge][1]][0]++;
        edge_io[edges[edge][0]][1]++;
    }

    for (int i = 1; i <= 1000001; i++) {
        if (edge_io[i][0] == 0 && edge_io[i][1] == 0) {
            break;
        }

        if (edge_io[i][1] == 0) {
            answer[2]++;
        } else if (edge_io[i][0] == 0 && edge_io[i][1] >= 2) {
            answer[0] = i;
        } else if (edge_io[i][0] >= 2 && edge_io[i][1] == 2) {
            answer[3]++;
        }
    }

    answer[1] = edge_io[answer[0]][1] - answer[2] - answer[3];

    return answer;
}

int main(void) {
    // edges:[[2, 3], [4, 3], [1, 1], [2, 1]]
    // return:[2, 1, 1, 0]
    int **edges = (int **) malloc(sizeof(int *) << 2);
    for (int i = 0; i < 4; i++) {
        edges[i] = (int *) malloc(sizeof(int) << 1);
    }
    edges[0][0] = 2;
    edges[0][1] = 3;
    edges[1][0] = 4;
    edges[1][1] = 3;
    edges[2][0] = 1;
    edges[2][1] = 1;
    edges[3][0] = 2;
    edges[3][1] = 1;
    size_t edges_rows = 4;
    size_t edges_cols = 2;

    int *ret = solution(edges, edges_rows, edges_cols);
    printf("%d %d %d %d\n", ret[0], ret[1], ret[2], ret[3]);
}