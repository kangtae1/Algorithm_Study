#include <iostream>

using namespace std;

void check(char (*board)[50], int &max, int N) {
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == board[i][j + 1]) {
                count++;
            } else {
                if (max < count) {
                    max = count;
                }
                count = 1;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        int count = 1;
        for (int i = 0; i < N; i++) {
            if (board[i][j] == board[i + 1][j]) {
                count++;
            } else {
                if (max < count) {
                    max = count;
                }
                count = 1;
            }
        }
    }
}

void fasterCheck(char (*board)[50], int &max, int N, int start_row, int end_row, int start_col, int end_col) {
    for (int i = start_row; i <= end_row; i++) {
        int count = 1;
        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count > max) {
                max = count;
            }
        }
    }

    for (int j = start_col; j <= end_col; j++) {
        int count = 1;
        for (int i = 0; i < N - 1; i++) {
            if (board[i][j] == board[i + 1][j]) {
                count++;
            } else {
                count = 1;
            }

            if (count > max) {
                max = count;
                \
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    char board[50][50];
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - 1) {
                swap(board[i][j], board[i][j + 1]);
                fasterCheck(board, max, N, i, i, j, j + 1);
                swap(board[i][j], board[i][j + 1]);

                swap(board[j][i], board[j + 1][i]);
                fasterCheck(board, max, N, j, j + 1, i, i);
                swap(board[j][i], board[j + 1][i]);
            }
        }
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N - 1; j++) {
//            check(board, max, N);
//
//            swap(board[i][j], board[i][j + 1]);
//            check(board, max, N);
//            swap(board[i][j], board[i][j + 1]);
//
//            swap(board[j][i], board[j + 1][i]);
//            check(board, max, N);
//            swap(board[j][i], board[j + 1][i]);
//        }
//    }

    cout << max << endl;
}