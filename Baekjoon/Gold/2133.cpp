#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (n % 2 == 1 || n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int dp[31];
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[n] << endl;

    return 0;
}