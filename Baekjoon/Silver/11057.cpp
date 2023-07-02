#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[1001][10] = {0, };
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[N][i];
    }

    cout << sum % 10007 << endl;

    return 0;
}