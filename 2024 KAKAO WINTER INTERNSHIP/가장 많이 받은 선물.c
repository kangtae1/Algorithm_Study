#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>

#define FRIENDS_LEN_MAX 50

typedef struct map {
    char *key;
    int value;
} map_t;

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char *friends[], size_t friends_len, const char *gifts[], size_t gifts_len) {
    int answer = 0;

    map_t friend_map[FRIENDS_LEN_MAX] = {NULL,};
    int gift_log[FRIENDS_LEN_MAX][FRIENDS_LEN_MAX] = {0,};
    int gift_index[FRIENDS_LEN_MAX] = {0,};
    int gift_count[FRIENDS_LEN_MAX] = {0,};

    for (int friend_idx = 0; friend_idx < friends_len; friend_idx++) {
        friend_map[friend_idx].key = friends[friend_idx];
        friend_map[friend_idx].value = friend_idx;
    }

    for (int gift_idx = 0; gift_idx < gifts_len; gift_idx++) {
        char gift[22];
        strcpy(gift, gifts[gift_idx]);
        char *friend1 = strtok(gift, " ");
        char *friend2 = strtok(NULL, " ");

        int friend1_idx = 0;
        int friend2_idx = 0;
        for (int map_idx = 0; map_idx < friends_len; map_idx++) {
            if (strcmp(friend_map[map_idx].key, friend1) == 0) {
                friend1_idx = friend_map[map_idx].value;
            }
            if (strcmp(friend_map[map_idx].key, friend2) == 0) {
                friend2_idx = friend_map[map_idx].value;
            }
        }

        gift_log[friend1_idx][friend2_idx]++;
        gift_index[friend1_idx]++;
        gift_index[friend2_idx]--;
    }

    for (int i = 0; i < friends_len; i++) {
        for (int j = 0; j < friends_len; j++) {
            if (gift_log[i][j] > gift_log[j][i]) {
                gift_count[i]++;
            } else if (gift_log[i][j] == gift_log[j][i]) {
                if (gift_index[i] > gift_index[j]) {
                    gift_count[i]++;
                }
            }
        }
    }

    for (int i = 0; i < friends_len; i++) {
        if (answer < gift_count[i]) {
            answer = gift_count[i];
        }
    }

    return answer;
}

int main(void) {
    // friends: ["joy", "brad", "alessandro", "conan", "david"]
    // gifts: ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]
    // return: 4
    const char *friends[5] = {"joy", "brad", "alessandro", "conan", "david"};
    const char *gifts[5] = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david", "joy brad", "joy conan", "joy david"};
    size_t friends_len = 5;
    size_t gifts_len = 5;

    printf("%d\n", solution(friends, friends_len, gifts, gifts_len));
    return 0;
}