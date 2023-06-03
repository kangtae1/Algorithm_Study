#include <iostream>

#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[n + 1][3];
    int dp[n + 1][3];

    fill_n(dp[0], 3, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + cost[i][RED];
        dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + cost[i][GREEN];
        dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + cost[i][BLUE];
    }

    cout << min(min(dp[n][RED], dp[n][GREEN]), dp[n][BLUE]);
}