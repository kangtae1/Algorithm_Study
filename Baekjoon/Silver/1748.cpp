#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    for (int i = 1; i <= N; i *= 10) {
        sum += N - i + 1;
    }

    cout << sum << '\n';

    return 0;
}