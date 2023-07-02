#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int glass[10001] = {0, };
    for (int i = 1; i <= N; i++) {
        cin >> glass[i];
    }

    int dp[10001] = {0, };
    dp[1] = glass[1];
    dp[2] = glass[1] + glass[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]));
    }

    cout << dp[N] << endl;

    return 0;
}