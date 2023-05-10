#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int P[n + 1];
    int DP[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    fill_n(DP, n + 1, INT_MAX);
    DP[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
              DP[i] = min(DP[i], DP[i - j] + P[j]);
        }
    }
    cout << DP[n] << endl;

    return 0;
}
