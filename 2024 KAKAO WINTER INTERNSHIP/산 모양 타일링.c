#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// tops_len은 배열 tops의 길이입니다.
int solution(int n, int tops[], size_t tops_len) {
    int answer = 0;

    int dp[200001] = {0,};
    dp[0] = 1;
    dp[1] = tops[0] ? 3 : 2;

    for (int i = 2; i < n * 2 + 1; i++) {
        if (i % 2 && tops[i / 2]) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 10007;
        } else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }
    answer = dp[n * 2];

    return answer;
}

int main(void) {
    // n = 4, tops = [1, 1, 0, 1], result = 149
    int n = 4;
    int tops[] = {1, 1, 0, 1};
    size_t tops_len = 4;
    int result = solution(n, tops, tops_len);
    printf("%d\n", result);
}