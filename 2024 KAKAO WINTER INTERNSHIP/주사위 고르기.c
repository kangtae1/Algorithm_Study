#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int combination(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    } else {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int get_sum(int arr[][6], int depth, int idx, int n) {
    if (depth == n) {
        return arr[depth - 1][idx];
    } else {
        return arr[depth - 1][idx % 6] + get_sum(arr, depth + 1, idx / 6, n);
    }
}

int *selected_masks(int n) {
    int combination_count = combination(n, n >> 1);
    int *masks = (int *) malloc(sizeof(int) * combination_count);
    memset(masks, 0, sizeof(int) * combination_count);

    masks[0] = (1 << (n >> 1)) - 1;
    for (int i = 1; i < combination_count; i++) {
        int mask = masks[i - 1];
        int x = mask & -mask;
        int y = mask + x;
        int z = mask & ~y;
        masks[i] = z / x >> 1 | y;
    }

    return masks;
}

// dice_rows는 2차원 배열 dice의 행 길이, dice_cols는 2차원 배열 dice의 열 길이입니다.
int *solution(int **dice, size_t dice_rows, size_t dice_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *) malloc(sizeof(int) * (dice_rows >> 1));
    memset(answer, 0, sizeof(int) * (dice_rows >> 1));

    int *masks = selected_masks(dice_rows);
    int mask_size = combination(dice_rows, dice_rows >> 1);
    int *sums = (int *) malloc(sizeof(int) * mask_size);

    int dice_a[dice_rows >> 1][dice_cols];
    int dice_b[dice_rows >> 1][dice_cols];


    for (int mask_idx = 0; mask_idx < mask_size; mask_idx++) {
        int dice_a_index = 0;
        int dice_b_index = 0;
        for (int i = 0; i < dice_rows; i++) {
            if ((masks[mask_idx] >> i) & 0x1 == 1) {
                for (int j = 0; j < dice_cols; j++) {
                    dice_a[dice_a_index][j] = dice[i][j];
                }
                dice_a_index++;
            } else {
                for (int j = 0; j < dice_cols; j++) {
                    dice_b[dice_b_index][j] = dice[i][j];
                }
                dice_b_index++;
            }
        }

        int len = pow(dice_cols, dice_rows >> 1);

        int dice_a_sum[len];
        for (int i = 0; i < len; i++) {
            dice_a_sum[i] = get_sum(dice_a, 1, i, dice_rows >> 1);
        }

        int dice_b_sum[len];
        for (int i = 0; i < len; i++) {
            dice_b_sum[i] = get_sum(dice_b, 1, i, dice_rows >> 1);
        }

        int sum = 0;
        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int j = 0; j < len; j++) {
                if (dice_a_sum[i] > dice_b_sum[j]) {
                    count++;
                }
            }
            sum += count;
        }
        sums[mask_idx] = sum;
    }

    int max_sum_idx = 0;
    for (int i = 1; i < mask_size; i++) {
        if (sums[max_sum_idx] < sums[i]) {
            max_sum_idx = i;
        }
    }

    int answer_index = 0;
    for (int i = 0; i < dice_rows; i++) {
        if ((masks[max_sum_idx] >> i) & 0x1) {
            answer[answer_index++] = i + 1;
        }
    }

    return answer;
}

int main(void) {
    // dice: [[1, 2, 3, 4, 5, 6], [3, 3, 3, 3, 4, 4], [1, 3, 3, 4, 4, 4], [1, 1, 4, 4, 5, 5]]
    // return: [1, 4]

    int **dice = (int **) malloc(sizeof(int *) << 2);
    for (int i = 0; i < 4; i++) {
        dice[i] = (int *) malloc(sizeof(int) << 3);
    }
    dice[0][0] = 1;
    dice[0][1] = 2;
    dice[0][2] = 3;
    dice[0][3] = 4;
    dice[0][4] = 5;
    dice[0][5] = 6;
    dice[1][0] = 3;
    dice[1][1] = 3;
    dice[1][2] = 3;
    dice[1][3] = 3;
    dice[1][4] = 4;
    dice[1][5] = 4;
    dice[2][0] = 1;
    dice[2][1] = 3;
    dice[2][2] = 3;
    dice[2][3] = 4;
    dice[2][4] = 4;
    dice[2][5] = 4;
    dice[3][0] = 1;
    dice[3][1] = 1;
    dice[3][2] = 4;
    dice[3][3] = 4;
    dice[3][4] = 5;
    dice[3][5] = 5;
    size_t dice_rows = 4;
    size_t dice_cols = 6;

    int *ret = solution(dice, dice_rows, dice_cols);
    for (int i = 0; i < dice_rows >> 1; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}