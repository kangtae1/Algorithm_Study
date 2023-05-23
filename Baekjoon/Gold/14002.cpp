#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int dp[N];
    fill_n(dp, N, 1);
    int prev[N];
    fill_n(prev, N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int max = 0;
    int max_index = 0;
    for (int i = 0; i < N; i++) {
        if (max < dp[i]) {
            max = dp[i];
            max_index = i;
        }
    }

    cout << max << endl;

    int result[max];
    int result_index = max - 1;
    int index = max_index;
    while (index != -1) {
        result[result_index--] = A[index];
        index = prev[index];
    }

    for (int i = 0; i < max; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}