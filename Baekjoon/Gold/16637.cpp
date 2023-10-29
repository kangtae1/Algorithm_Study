#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, ans = INT_MIN;
char str[20];

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else return a * b;
}

void dfs(char* ptr, int cur) {
    if (*ptr == '\0') {
        ans = max(ans, cur);
        return;
    }

    char op = *(ptr - 1);
    if (ptr == str) op = '+';

    dfs(ptr + 2, calc(cur, *ptr - '0', op));

    if (*(ptr + 2) != '\0') {
        int tmp = calc(*ptr - '0', *(ptr + 2) - '0', *(ptr + 1));
        dfs(ptr + 4, calc(cur, tmp, op));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> str;

    dfs(str, 0);
    cout << ans;
    return 0;
}
