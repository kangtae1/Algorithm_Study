#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queue1_len은 배열 queue1의 길이입니다.
// queue2_len은 배열 queue2의 길이입니다.
int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    int answer = 0;

    int *v = (int *)malloc(sizeof(int) * (queue1_len + queue2_len));
    int start1 = 0, end1 = queue1_len - 1;
    int start2 = queue1_len, end2 = queue1_len + queue2_len - 1;

    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < queue1_len; i++) {
        sum1 += queue1[i];
        v[i] = queue1[i];
    }
    for (int i = 0; i < queue2_len; i++) {
        sum2 += queue2[i];
        v[i + queue1_len] = queue2[i];
    }

    while (answer <= queue1_len * 2 + queue2_len) {
        if (sum1 < sum2) {
            sum1 += v[(++end1) % (queue1_len + queue2_len)];
            sum2 -= v[(start2++) % (queue1_len + queue2_len)];
        } else if (sum1 > sum2) {
            sum1 -= v[(start1++) % (queue1_len + queue2_len)];
            sum2 += v[(++end2) % (queue1_len + queue2_len)];
        } else {
            free(v);
            return answer;
        }
        answer++;
    }

    free(v);
    return -1;
}

// 테스트케이스 출력용 main 함수
int main() {
    int queue1[] = {2, 2};
    int queue2[] = {1, 1};
    int ret = solution(queue1, 2, queue2, 2);

    printf("%d\n", ret);
}