#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int ans = 2e9;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int cnt = 0;
            if (i != 0) cnt++;
            if (j != 0) cnt++;

            int diff = v[1] + j - (v[0] + i);
            int prev = v[1] + j;
            bool flag = true;

            for (int k = 2; k < N; k++) {
                int next = prev + diff;
                int tmp = next - v[k];
                if (tmp == 0) {
                    prev = next;
                    continue;
                } else if (tmp == 1 || tmp == -1) {
                    cnt++;
                    prev = next;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = min(ans, cnt);
        }
    }

    if (ans == 2e9) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}