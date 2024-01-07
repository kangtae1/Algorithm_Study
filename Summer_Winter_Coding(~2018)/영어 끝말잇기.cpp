#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> used_words;
    int turn = 0;
    int cnt = 0;

    for (int i = 0; i < words.size(); i++) {
        cnt++;
        if (cnt > n) {
            cnt = 1;
            turn++;
        }

        if (!used_words.empty() &&
            (used_words.back()[used_words.back().size() - 1] != words[i][0] ||
             find(used_words.begin(), used_words.end(), words[i]) != used_words.end())) {
            answer.push_back(cnt);
            answer.push_back(turn + 1);
            break;
        }

        used_words.push_back(words[i]);
    }

    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {
    int n = 3;
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};

    vector<int> ret = solution(n, words);

    printf("%d %d\n", ret[0], ret[1]);
}