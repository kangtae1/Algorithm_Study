#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int type_to_index(char type);
bool isInversed(const char *survey);

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char *answer = (char *) malloc(sizeof(char) * 5);
    int scores[4] = {0};

    for (size_t i = 0; i < survey_len; i++) {
        char disagree_type = survey[i][0];
        char agree_type = survey[i][1];
        bool inverse = isInversed(survey[i]);
        int choice = choices[i];

        if (choice == 1 || choice == 2 || choice == 3) {
            scores[type_to_index(disagree_type)] += (4 - choice) * (inverse ? -1 : 1);
        } else if (choice == 5 || choice == 6 || choice == 7) {
            scores[type_to_index(agree_type)] -= (choice - 4) * (inverse ? -1 : 1);
        } else {
            continue;
        }
    }

    if (scores[0] >= 0) {
        answer[0] = 'R';
    } else {
        answer[0] = 'T';
    }
    if (scores[1] >= 0) {
        answer[1] = 'C';
    } else {
        answer[1] = 'F';
    }
    if (scores[2] >= 0) {
        answer[2] = 'J';
    } else {
        answer[2] = 'M';
    }
    if (scores[3] >= 0) {
        answer[3] = 'A';
    } else {
        answer[3] = 'N';
    }
    answer[4] = '\0';

    return answer;
}

int type_to_index(char type) {
    if (type == 'R' || type == 'T') {
        return 0;
    } else if (type == 'C' || type == 'F') {
        return 1;
    } else if (type == 'J' || type == 'M') {
        return 2;
    } else if (type == 'A' || type == 'N') {
        return 3;
    } else {
        return -1;
    }
}

bool isInversed(const char *survey) {
    if (survey[0] == 'R' || survey[0] == 'C' || survey[0] == 'J' || survey[0] == 'A') {
        return false;
    } else {
        return true;
    }
}

int main() {
    const char *survey1[] = {"AN", "CF", "MJ", "RT", "NA"};
    int choices1[] = {5, 3, 2, 7, 5};
    char *result1 = solution(survey1, 5, choices1, 5);
    printf("Result: %s\n", result1);
    free(result1);

    const char *survey2[] = {"TR", "RT", "TR"};
    int choices2[] = {7, 1, 3};
    char *result2 = solution(survey2, 3, choices2, 3);
    printf("Result: %s\n", result2);
    free(result2);

    return 0;
}
