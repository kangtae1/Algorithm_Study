#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int str_to_date(const char *date_s) {
    int year, month, date;
    sscanf(date_s, "%d.%d.%d", &year, &month, &date);
    return (year * 12 + month) * 28 + date;
}

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int *solution(const char *today, const char *terms[], size_t terms_len, const char *privacies[], size_t privacies_len) {
    int term_arr[26]; // A ~ Z
    int pre_answers[100]; // privacies_len <= 100
    int answers_len = 0;

    for (int i = 0; i < terms_len; i++) {
        term_arr[terms[i][0] - 'A'] = (int)strtol(terms[i] + 2, NULL, 10);
    }

    for (int i = 0; i < privacies_len; i++) {
        if (str_to_date(privacies[i]) + term_arr[privacies[i][11] - 'A'] * 28 <= str_to_date(today)) {
            pre_answers[answers_len++] = i + 1;
        }
    }

    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = malloc(sizeof answer[0] * answers_len);
    memcpy(answer, pre_answers, sizeof answer[0] * answers_len);
    return answer;
}

int main() {
    const char *today = "2022.05.19";
    const char *terms[] = {"A 6", "B 12", "C 3"};
    const char *privacies[] = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    size_t terms_len = 3;
    size_t privacies_len = 4;
    int *ret = solution(today, terms, terms_len, privacies, privacies_len);

    printf("{");
    for (int i = 0; i < 2; i++) {
        printf("%d", ret[i]);
        if (i != 2 - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    free(ret);
    return 0;
}