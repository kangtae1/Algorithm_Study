#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int x1 = v[i].first, y1 = v[i].second;
        for (int j = i + 1; j < N; j++) { // 크아아아아악
            int x2 = v[j].first, y2 = v[j].second;
            if ((x1 + x2 <= H && max(y1, y2) <= W) || (x1 + y2 <= H && max(y1, x2) <= W) ||
                (y1 + x2 <= H && max(x1, y2) <= W) || (y1 + y2 <= H && max(x1, x2) <= W) ||
                (x1 + x2 <= W && max(y1, y2) <= H) || (x1 + y2 <= W && max(y1, x2) <= H) ||
                (y1 + x2 <= W && max(x1, y2) <= H) || (y1 + y2 <= W && max(x1, x2) <= H)) {
                ans = max(ans, x1 * y1 + x2 * y2);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}