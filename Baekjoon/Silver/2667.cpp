#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[25][25];
int visited[25][25];
int cnt = 0;
vector<int> v;

void dfs(int x, int y) {
    visited[x][y] = 1;
    cnt++;
    if (x > 0 && map[x - 1][y] == 1 && visited[x - 1][y] == 0) {
        dfs(x - 1, y);
    }
    if (x < N - 1 && map[x + 1][y] == 1 && visited[x + 1][y] == 0) {
        dfs(x + 1, y);
    }
    if (y > 0 && map[x][y - 1] == 1 && visited[x][y - 1] == 0) {
        dfs(x, y - 1);
    }
    if (y < N - 1 && map[x][y + 1] == 1 && visited[x][y + 1] == 0) {
        dfs(x, y + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    int complex = 0;
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                complex++;
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << complex << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}