#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[1001] = {0, };
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int dp[1001] = {0, };
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[i] < A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    cout << max << endl;

    return 0;
}