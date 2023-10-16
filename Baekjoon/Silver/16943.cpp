#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    cin >> A >> B;
    sort(A.begin(), A.end());

    int ans = -1;
    do {
        if (A[0] == '0') continue;

        int num = stoi(A);
        if (num <= stoi(B)) ans = max(ans, num);
    } while (next_permutation(A.begin(), A.end()));
    cout << ans << '\n';
    return 0;
}
