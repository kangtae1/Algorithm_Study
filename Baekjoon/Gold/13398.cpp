#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[100001];
    int dp[100001];
    int dp2[100001];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = a[1];
    int ans = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }

    dp2[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        dp2[i] = max(dp2[i + 1] + a[i], a[i]);
        ans = max(ans, dp2[i]);
    }

    for (int i = 2; i < n; i++) {
        ans = max(ans, dp[i - 1] + dp2[i + 1]);
    }

    cout << ans << '\n';

    return 0;
}