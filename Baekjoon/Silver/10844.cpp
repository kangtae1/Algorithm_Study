#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int64_t DP[101][10] = {0, };
    for (int i = 1; i <= 9; i++) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        DP[i][0] = DP[i - 1][1];
        DP[i][9] = DP[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
        }
    }

    int64_t sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += DP[n][i];
    }
    cout << sum % 1000000000 << endl;

    return 0;
}