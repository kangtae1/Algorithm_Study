#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[1001] = {0, };
    for (int i = 1; i <= N; i++) {
        cin >> dp[i];
    }

    int dp2[1001] = {0, };
    for (int i = 1; i <= N; i++) {
        dp2[i] = dp[i];
        for (int j = 1; j < i; j++) {
            if (dp[i] > dp[j] && dp2[i] < dp2[j] + dp[i]) {
                dp2[i] = dp2[j] + dp[i];
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (dp2[i] > max) {
            max = dp2[i];
        }
    }

    cout << max << endl;

    return 0;
}