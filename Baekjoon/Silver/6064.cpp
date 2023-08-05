#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M, N, x, y;
    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;

        int max = lcm(M, N);

        while (x <= max && (x - 1) % N + 1 != y)
            x += M;

        if (x > max) cout << -1 << '\n';
        else cout << x << '\n';
    }

    return 0;
}