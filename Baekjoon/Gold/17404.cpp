#include <iostream>
#define MIN_INIT 1000000 // 1000 * 1000

using namespace std;

int main() {
    int N;
    cin >> N;
    int cost[N][3];
    int dp[N][3];
    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    int min = MIN_INIT;

    for (int i = 0; i < 3; i++) {
        dp[0][0] = MIN_INIT;
        dp[0][1] = MIN_INIT;
        dp[0][2] = MIN_INIT;
        dp[0][i] = cost[0][i];

        for (int j = 1; j < N; j++) {
            dp[j][0] = (dp[j - 1][1] < dp[j - 1][2] ? dp[j - 1][1] : dp[j - 1][2]) + cost[j][0];
            dp[j][1] = (dp[j - 1][0] < dp[j - 1][2] ? dp[j - 1][0] : dp[j - 1][2]) + cost[j][1];
            dp[j][2] = (dp[j - 1][0] < dp[j - 1][1] ? dp[j - 1][0] : dp[j - 1][1]) + cost[j][2];
        }

        for (int j = 0; j < 3; j++) {
            if (j != i && min > dp[N - 1][j]) {
                min = dp[N - 1][j];
            }
        }
    }

    cout << min << endl;
    return 0;
}