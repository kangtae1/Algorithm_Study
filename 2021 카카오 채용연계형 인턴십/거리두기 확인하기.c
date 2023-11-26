#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isSafe(const char **places, int x1, int y1, int x2, int y2) {
    // 맨해튼 거리가 1인 경우 무조건 위반
    if (manhattanDistance(x1, y1, x2, y2) == 1) {
        return false;
    }
    // 맨해튼 거리가 2이면서 파티션이 없는 경우 거리두기 위반
    if (manhattanDistance(x1, y1, x2, y2) == 2) {
        // 파티션 사이에 있는 경우는 거리두기 지켜짐
        if (places[(x1 + x2) / 2][(y1 + y2) / 2] == 'X') {
            return true;
        }
        // 대각선에 파티션을 낀 경우는 거리두기 지켜짐
        if (places[x1][y2] == 'X' && places[x2][y1] == 'X') {
            return true;
        }
        return false;
    }
    return true;
}

bool checkDistancing(const char **places) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (places[i][j] == 'P') {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        if (places[k][l] == 'P' && (i != k || j != l)) {
                            if (!isSafe(places, i, j, k, l)) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

// places_rows는 2차원 배열 places의 행 길이, places_cols는 2차원 배열 places의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int *solution(const char ***places, size_t places_rows, size_t places_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *) malloc(places_rows * sizeof(int));

    for (size_t i = 0; i < places_rows; i++) {
        if (checkDistancing(places[i])) {
            answer[i] = 1;
        } else {
            answer[i] = 0;
        }
    }

    return answer;
}

int main() {
    const char *place1[5] = {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"};
    const char *place2[5] = {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"};
    const char *place3[5] = {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"};
    const char *place4[5] = {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"};
    const char *place5[5] = {"PXPOP", "XXXXX", "XXXXX", "XXXXX", "XXXXX"};

    const char ***places = (const char ***) malloc(5 * sizeof(const char **));
    places[0] = place1;
    places[1] = place2;
    places[2] = place3;
    places[3] = place4;
    places[4] = place5;

    int *result = solution(places, 5, 5);

    printf("[");
    for (size_t i = 0; i < 5; i++) {
        printf("%d", result[i]);
        if (i < 4) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    free(places);

    return 0;
}
