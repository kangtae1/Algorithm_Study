#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int idx;
    Node *prev;
    Node *next;

    Node(int _idx) : idx(_idx), prev(nullptr), next(nullptr) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    stack<Node *> deletedRows;

    vector<Node *> rows(n);
    for (int i = 0; i < n; ++i) {
        rows[i] = new Node(i);
        if (i > 0) {
            rows[i]->prev = rows[i - 1];
            rows[i - 1]->next = rows[i];
        }
    }

    Node *currentRow = rows[k];

    for (auto &command: cmd) {
        char action = command[0];

        if (action == 'U' || action == 'D') {
            int x = stoi(command.substr(2));

            if (action == 'U') {
                while (x--) {
                    currentRow = currentRow->prev;
                }
            } else {
                while (x--) {
                    currentRow = currentRow->next;
                }
            }
        } else if (action == 'C') {
            deletedRows.push(currentRow);
            answer[currentRow->idx] = 'X';

            if (currentRow->prev) {
                currentRow->prev->next = currentRow->next;
            }
            if (currentRow->next) {
                currentRow->next->prev = currentRow->prev;
            }

            if (currentRow->next) {
                currentRow = currentRow->next;
            } else {
                currentRow = currentRow->prev;
            }
        } else if (action == 'Z') {
            Node *restoredRow = deletedRows.top();
            deletedRows.pop();
            answer[restoredRow->idx] = 'O';

            if (restoredRow->prev) {
                restoredRow->prev->next = restoredRow;
            }
            if (restoredRow->next) {
                restoredRow->next->prev = restoredRow;
            }
        }
    }

    return answer;
}

int main() {
    int n = 8;
    int k = 2;
    vector<string> cmd = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"};

    string ret = solution(n, k, cmd);

    printf("%s\n", ret.c_str());
}