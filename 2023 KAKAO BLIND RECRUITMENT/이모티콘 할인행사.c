#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

int g_answer[2];
int g_emoticon_prices[7][2];
int g_discount[4] = {10, 20, 30, 40};

void dfs(int emoticon, int **users, size_t users_rows, size_t users_cols, int emoticons[], size_t emoticons_len) {
    if (emoticon < emoticons_len) {
        for (int i = 0; i < 4; i++) {
            g_emoticon_prices[emoticon][0] = emoticons[emoticon] * (100 - g_discount[i]) / 100;
            g_emoticon_prices[emoticon][1] = g_discount[i];
            dfs(emoticon + 1, users, users_rows, users_cols, emoticons, emoticons_len);
        }
    } else {
        int subscribe = 0;
        int purchase_prices = 0;

        for (int i = 0; i < users_rows; ++i) {
            int total_price = 0;
            for (int j = 0; j < emoticons_len; ++j) {
                if (g_emoticon_prices[j][1] >= users[i][0])
                    total_price += g_emoticon_prices[j][0];
            }

            if (total_price >= users[i][1])
                ++subscribe;
            else
                purchase_prices += total_price;
        }

        if (subscribe > g_answer[0]) {
            g_answer[0] = subscribe;
            g_answer[1] = purchase_prices;
        } else if (subscribe == g_answer[0]) {
            if (purchase_prices > g_answer[1])
                g_answer[1] = purchase_prices;
        }
        return;
    }
}

// users_rows는 2차원 배열 users의 행 길이, users_cols는 2차원 배열 users의 열 길이입니다.
// emoticons_len은 배열 emoticons의 길이입니다.
int *solution(int **users, size_t users_rows, size_t users_cols, int emoticons[], size_t emoticons_len) {
    dfs(0, users, users_rows, users_cols, emoticons, emoticons_len);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *) malloc(sizeof(int) * 2);
    memcpy(answer, g_answer, sizeof(int) * 2);
    return answer;
}

int main() {
    int **users = (int **) malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        users[i] = (int *) malloc(sizeof(int) * 2);
    }
    users[0][0] = 40;
    users[0][1] = 10000;
    users[1][0] = 25;
    users[1][1] = 10000;

    int *emoticons = (int *) malloc(sizeof(int) * 2);
    emoticons[0] = 7000;
    emoticons[1] = 9000;

    int *ret = solution(users, 2, 2, emoticons, 2);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", ret[i]);
    }
}