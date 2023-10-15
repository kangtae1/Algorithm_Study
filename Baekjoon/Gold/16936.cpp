#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<long long> B;
vector<long long> A;

int N;

void solve(long long num, int depth) {
    if (depth == N) {
        return;
    }

    if (num % 3 == 0 && B.find(num / 3) != B.end()) {
        A.push_back(num / 3);
        solve(num / 3, depth + 1);
    }

    if (B.find(num * 2) != B.end()) {
        A.push_back(num * 2);
        solve(num * 2, depth + 1);
    }

    return;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        B.insert(num);
    }

    for (auto it = B.begin(); it != B.end(); it++) {
        A.push_back(*it);
        solve(*it, 1);
        if (A.size() == N) {
            break;
        }
        A.clear();
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}