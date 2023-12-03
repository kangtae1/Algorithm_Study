#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> gems_set(gems.begin(), gems.end());
    int gem_cnt = gems_set.size();

    int start = 0, end = 0;

    map<string, int> gems_map;

    for (auto &gem: gems) {
        gems_map[gem]++;
        if (gems_map.size() == gem_cnt) {
            break;
        }
        end++;
    }

    int min_section_len = end - start;

    answer.push_back(start + 1);
    answer.push_back(end + 1);

    while (end < gems.size()) {
        string key = gems[start++];
        gems_map[key]--;

        if (gems_map[key] == 0) {
            end++;
            for (; end < gems.size(); end++) {
                gems_map[gems[end]]++;
                if (key == gems[end])
                    break;
            }
            if (end == gems.size()) break;
        }
        if (min_section_len > end - start) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            min_section_len = end - start;
        }
    }

    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> ret = solution(gems);

    printf("%d %d\n", ret[0], ret[1]);
}