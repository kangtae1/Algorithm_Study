#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int n[T], max = 0;
    for (int i = 0; i < T; i++) {
        cin >> n[i];
        max = max > n[i] ? max : n[i];
    }

    int64_t dp[1000001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= max; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }

    for (int i = 0; i < T; i++) {
        cout << dp[n[i]] << endl;
    }

//    while (T--) {
//        int n;
//        cin >> n;
//
//        int64_t dp[1000001];
//        dp[1] = 1;
//        dp[2] = 2;
//        dp[3] = 4;
//
//        for (int i = 4; i <= n; i++) {
//            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
//        }
//
//        cout << dp[n] << endl;
//    }
}