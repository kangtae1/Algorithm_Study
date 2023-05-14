#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        int64_t DP[100001][4] = {0, };
        DP[1][1] = 1;
        // else: 0
        DP[2][2] = 1;
        // else: 0
        DP[3][1] = 1;
        DP[3][2] = 1;
        DP[3][3] = 1;

        for (int i = 4; i <= n; i++) {
            DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % 1000000009;
            DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % 1000000009;
            DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % 1000000009;
        }
        cout << (DP[n][1] + DP[n][2] + DP[n][3]) % 1000000009 << endl;
    }

    return 0;
}