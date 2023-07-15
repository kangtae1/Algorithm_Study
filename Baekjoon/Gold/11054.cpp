#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int A[1001];
    int dp[1001];
    int dp2[1001];
    int ans = 0;

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = 1;
        dp2[i] = 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(A[i] > A[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }
    for(int i = N; i >= 1; i--) {
        for(int j = N; j > i; j--) {
            if(A[i] > A[j] && dp2[i] < dp2[j] + 1) dp2[i] = dp2[j] + 1;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(ans < dp[i] + dp2[i] - 1)
            ans = dp[i] + dp2[i] - 1;
    }

    cout << ans << '\n';
    return 0;
}