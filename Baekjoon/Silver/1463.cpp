#include <iostream>

using namespace std;

int solve(int n) {
    if (n == 0 || n == 1) return 0;
    int m3 = n % 3;
    int m2 = n % 2;
    return min(m3 + solve(n / 3), m2 + solve(n / 2)) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}