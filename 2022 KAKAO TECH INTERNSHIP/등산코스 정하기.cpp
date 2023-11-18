#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    int dist[50001];
    fill(dist + 1, dist + 50001, -1);

    vector<pair<int, int>> graph[50001]; // graph[from] = {to, weight}

    bool isSummit[50001];
    for (int i = 0; i < summits.size(); i++) isSummit[summits[i]] = true;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // {pos, intensity}
    for (int i = 0; i < gates.size(); i++) {
        dist[gates[i]] = 0;
        pq.push({gates[i], 0});
    }

    vector<pair<int, int>> result;

    for (int i = 0; i < paths.size(); i++) { // 이게 그래프 선언쪽으로 올라가면 터지는 이유는?
        graph[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        graph[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (dist[cur.first] < cur.second) continue;

        if (isSummit[cur.first]) {
            result.push_back({cur.second, cur.first});
            continue;
        }

        for (auto next : graph[cur.first]) {
            int np = next.first, w = next.second;

            if (dist[np] != -1 && dist[np] <= max(cur.second, w)) continue;

            dist[np] = max(cur.second, w);
            pq.push({np, dist[np]});
        }
    }

    sort(result.begin(), result.end());
    answer.push_back(result[0].second);
    answer.push_back(result[0].first);

    return answer;
}

// 테스트케이스 출력용 main 함수
int main() {
    int n = 5;
    vector<vector<int>> paths = {{1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}};
    vector<int> gates = {1, 2};
    vector<int> summits = {5};
    vector<int> ret = solution(n, paths, gates, summits);

    for (int i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}