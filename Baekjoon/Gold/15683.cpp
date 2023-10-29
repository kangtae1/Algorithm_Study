#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[8][8];
int cctv[8][8];
int cctv_num;
int cctv_dir[8];

int min_blind = 64;

vector<pair<int, int>> cctv_pos;

void copy_map(int a[8][8], int b[8][8]) {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) a[i][j] = b[i][j];
}

void check(int x, int y, int dir) {
    if (dir == 0) {
        for (int i = y + 1; i < M; i++) {
            if (map[x][i] == 6) break;
            if (map[x][i] == 0) map[x][i] = -1;
        }
    }
    else if (dir == 1) {
        for (int i = x + 1; i < N; i++) {
            if (map[i][y] == 6) break;
            if (map[i][y] == 0) map[i][y] = -1;
        }
    }
    else if (dir == 2) {
        for (int i = y - 1; i >= 0; i--) {
            if (map[x][i] == 6) break;
            if (map[x][i] == 0) map[x][i] = -1;
        }
    }
    else if (dir == 3) {
        for (int i = x - 1; i >= 0; i--) {
            if (map[i][y] == 6) break;
            if (map[i][y] == 0) map[i][y] = -1;
        }
    }
}

void dfs(int cnt) {
    if (cnt == cctv_num) {
        int blind = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (map[i][j] == 0) blind++;
        min_blind = min(min_blind, blind);
        return;
    }

    int temp_map[8][8];
    int temp_cctv_dir[8];
    copy_map(temp_map, map);
    for (int i = 0; i < cctv_num; i++) temp_cctv_dir[i] = cctv_dir[i];

    int x = cctv_pos[cnt].first;
    int y = cctv_pos[cnt].second;
    int cctv_type = cctv[x][y];

    if (cctv_type == 1) {
        for (int i = 0; i < 4; i++) {
            cctv_dir[cnt] = i;
            check(x, y, i);
            dfs(cnt + 1);
            copy_map(map, temp_map);
            for (int j = 0; j < cctv_num; j++) cctv_dir[j] = temp_cctv_dir[j];
        }
    }
    else if (cctv_type == 2) {
        for (int i = 0; i < 2; i++) {
            cctv_dir[cnt] = i;
            check(x, y, i);
            check(x, y, i + 2);
            dfs(cnt + 1);
            copy_map(map, temp_map);
            for (int j = 0; j < cctv_num; j++) cctv_dir[j] = temp_cctv_dir[j];
        }
    }
    else if (cctv_type == 3) {
        for (int i = 0; i < 4; i++) {
            cctv_dir[cnt] = i;
            check(x, y, i);
            check(x, y, (i + 1) % 4);
            dfs(cnt + 1);
            copy_map(map, temp_map);
            for (int j = 0; j < cctv_num; j++) cctv_dir[j] = temp_cctv_dir[j];
        }
    }
    else if (cctv_type == 4) {
        for (int i = 0; i < 4; i++) {
            cctv_dir[cnt] = i;
            check(x, y, i);
            check(x, y, (i + 1) % 4);
            check(x, y, (i + 2) % 4);
            dfs(cnt + 1);
            copy_map(map, temp_map);
            for (int j = 0; j < cctv_num; j++) cctv_dir[j] = temp_cctv_dir[j];
        }
    }
    else if (cctv_type == 5) {
        cctv_dir[cnt] = 0;
        check(x, y, 0);
        check(x, y, 1);
        check(x, y, 2);
        check(x, y, 3);
        dfs(cnt + 1);
        copy_map(map, temp_map);
        for (int j = 0; j < cctv_num; j++) cctv_dir[j] = temp_cctv_dir[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int cctv_cnt = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> map[i][j];
        if (map[i][j] != 0 && map[i][j] != 6) {
            cctv[i][j] = map[i][j];
            cctv_pos.push_back({ i, j });
            cctv_cnt++;
        }
    }

    cctv_num = cctv_cnt;
    dfs(0);

    cout << min_blind << '\n';

    return 0;
}