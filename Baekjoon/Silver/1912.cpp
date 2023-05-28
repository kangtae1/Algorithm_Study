#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100001] = {0,};
    int dp[100001] = {0,};

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    }

    cout << *max_element(&dp[1], &dp[n + 1]);
}