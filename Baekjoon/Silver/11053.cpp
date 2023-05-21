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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max << endl;

    return 0;
}