#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// cards_len은 배열 cards의 길이입니다.
int solution(int coin, int cards[], size_t cards_len) {
    int answer = 0;
    int hand_size = (int) cards_len / 3;  // 손에 들 수 있는 카드의 최대 개수
    int *hand = (int *) malloc(sizeof(int) * hand_size);  // 손에 들 카드
    int cards_end = hand_size;  // 다음으로 가져올 카드의 인덱스
    int cards_start = hand_size; // 다음으로 가져올 카드의 시작 인덱스
    int round_max = cards_len / 3 + 1;  // 최대 라운드 수

    for (int i = 0; i < hand_size; i++) {
        hand[i] = cards[i];
    }

    ROUND_START:
    answer++;
    cards_end += 2;

    for (int i = 0; i < hand_size; i++) {
        for (int j = i + 1; j < hand_size; j++) {
            if (i == j) continue;
            if (hand[i] + hand[j] == cards_len + 1) {
                hand[i] = 0;
                hand[j] = 0;
                // hand의 0을 맨 뒤로 이동
                for (size_t l = 0; l < hand_size + 2; l++) {
                    if (hand[l] == 0) {
                        for (size_t m = l + 1; m < hand_size + 2; m++) {
                            if (hand[m] != 0) {
                                swap(&hand[l], &hand[m]);
                                break;
                            }
                        }
                    }
                }
                hand_size -= 2;
                goto ROUND_START;
            }
        }
    }

    if (coin <= 0) goto GAME_END;
    for (int i = 0; i < hand_size; i++) {
        for (int j = cards_start; j < cards_end; j++) {
            if (cards[j] == 0) continue;
            if (hand[i] + cards[j] == cards_len + 1) {
                hand[i] = 0;
                cards[j] = 0;
                // hand의 0을 맨 뒤로 이동
                for (size_t l = 0; l < hand_size + 2; l++) {
                    if (hand[l] == 0) {
                        for (size_t m = l + 1; m < hand_size + 2; m++) {
                            if (hand[m] != 0) {
                                swap(&hand[l], &hand[m]);
                                break;
                            }
                        }
                    }
                }
                hand_size--;
                coin--;
                goto ROUND_START;
            }
        }
    }

    if (coin <= 1) goto GAME_END;
    for (int i = cards_start; i < cards_end; i++) {
        for (int j = i + 1; j < cards_end; j++) {
            if (i == j) continue;
            if (cards[i] == 0 || cards[j] == 0) continue;
            if (cards[i] + cards[j] == cards_len + 1) {
                cards[i] = 0;
                cards[j] = 0;
                coin -= 2;
                goto ROUND_START;
            }
        }
    }

    GAME_END:
    if (answer > round_max) answer = round_max;
    free(hand);
    return answer;
}

int main() {
    int coin = 8;
    int cards[] = {1, 12, 2, 11, 3, 10, 4, 9, 5, 8, 6, 7};
    size_t cards_len = sizeof(cards) / sizeof(cards[0]);

    int result = solution(coin, cards, cards_len);
    printf("최대 라운드 수: %d\n", result);

    return 0;
}
