#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R, X;
int answer = 0;
vector<int> v;

void dfs(int idx, int cnt, int sum, int max_val, int min_val) {
    if (cnt >= 2) {
        if (sum >= L && sum <= R && max_val - min_val >= X)
            answer++;
    }

    for (int i = idx; i < N; i++) {
        dfs(i + 1, cnt + 1, sum + v[i], max(max_val, v[i]), min(min_val, v[i]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    dfs(0, 0, 0, 0, 1000000000);
    cout << answer << endl;
    return 0;
}