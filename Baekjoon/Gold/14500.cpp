#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int **arr = new int *[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    int max = 0;

    // 1. ㅡ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 3; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
            if (sum > max) max = sum;
        }
    }

    // 2. ㅣ
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
            if (sum > max) max = sum;
        }
    }

    // 3. ㅁ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 4. L
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 5. L 회전1
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
            if (sum > max) max = sum;
        }
    }

    // 6. L 회전2
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 7. L 회전3
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j + 2] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            if (sum > max) max = sum;
        }
    }

    // 8. L 대칭
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j];
            if (sum > max) max = sum;
        }
    }

    // 9. L 대칭 회전1 == ㄴ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            if (sum > max) max = sum;
        }
    }

    // 10. L 대칭 회전2
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
            if (sum > max) max = sum;
        }
    }

    // 11. L 대칭 회전3 == ㄱ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
            if (sum > max) max = sum;
        }
    }

    // 12. ㄹ 1번
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 13. ㄹ 2번
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 14. ㄹ 3번
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j];
            if (sum > max) max = sum;
        }
    }

    // 15. ㄹ 4번
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            if (sum > max) max = sum;
        }
    }

    // 16. ㅜ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 17. ㅗ
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M - 2; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
            if (sum > max) max = sum;
        }
    }

    // 18. ㅏ
    for (int i = 0; i < N - 2; i++) {
        for (int j = 1; j < M; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
            if (sum > max) max = sum;
        }
    }

    // 19. ㅓ
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
            if (sum > max) max = sum;
        }
    }

    cout << max << endl;
}