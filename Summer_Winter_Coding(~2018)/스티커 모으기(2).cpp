#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker) {
    int answer = 0;
    int dp [100000][2] = {0, };
    int n = sticker.size();

    if (n == 1) {
        return sticker[0];
    }

    dp[0][0] = sticker[0];
    dp[1][0] = sticker[0];
    dp[1][1] = sticker[1];

    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + sticker[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + sticker[i]);
    }

    answer = max(dp[n - 2][0], dp[n - 1][1]);

    return answer;
}

int main() {
    vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};

    int ret = solution(sticker);

    printf("%d\n", ret);

    return 0;
}