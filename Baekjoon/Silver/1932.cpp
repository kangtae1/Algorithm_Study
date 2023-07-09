#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[501][501] = {0, };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] += dp[i - 1][j];
            }
            else if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[N][i] > max) {
            max = dp[N][i];
        }
    }

    cout << max << endl;

    return 0;
}