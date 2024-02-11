#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
    long long answer = 0;
    long long dliv_remain = 0;
    long long pickup_remain = 0;

    for (long long i = n - 1; i >= 0; i--) {
        long long count = 0;

        while (deliveries[i] > dliv_remain || pickups[i] > pickup_remain) {
            dliv_remain += cap;
            pickup_remain += cap;
            count++;
        }

        dliv_remain -= deliveries[i];
        pickup_remain -= pickups[i];

        answer += 2 * count * (i + 1);
    }

    return answer;

}

int main() {
    int deliveries[] = {1, 0, 3, 1, 2};
    int pickups[] = {0, 3, 0, 4, 0};
    printf("%lld\n", solution(4, 5, deliveries, 5, pickups, 5));
    return 0;
}