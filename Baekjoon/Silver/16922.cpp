#include <iostream>

using namespace std;

bool visited[1001] = {false,};
int N;
int answer;
int value[4] = {1, 5, 10, 50};

void DFS(int depth, int start, int sum) {
    if (depth == N) {
        if (!visited[sum]) {
            answer++;
            visited[sum] = true;
        }
        return;
    }

    for (int i = start; i < 4; i++) {
        DFS(depth + 1, i, sum + value[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    DFS(0, 0, 0);
    cout << answer << endl;
}
