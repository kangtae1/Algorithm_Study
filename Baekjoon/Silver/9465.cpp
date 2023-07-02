#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int dp[2][100001] = {0,};
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> dp[i][j];
            }
        }

        int dp2[2][100001] = {0,};
        dp2[0][1] = dp[0][1];
        dp2[1][1] = dp[1][1];
        for (int i = 2; i <= N; i++) {
            dp2[0][i] = max(dp2[1][i - 1], dp2[1][i - 2]) + dp[0][i];
            dp2[1][i] = max(dp2[0][i - 1], dp2[0][i - 2]) + dp[1][i];
        }

        cout << max(dp2[0][N], dp2[1][N]) << '\n';
    }

    return 0;
}