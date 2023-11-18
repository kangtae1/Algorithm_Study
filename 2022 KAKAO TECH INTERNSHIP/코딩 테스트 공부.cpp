#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;

    int alp_req = -1, cop_req = -1;
    for (auto problem: problems) {
        if (alp_req < problem[0]) alp_req = problem[0];
        if (cop_req < problem[1]) cop_req = problem[1];
    }

    if (alp >= alp_req && cop >= cop_req) return 0;

//    int dp[alp_req + 1][cop_req + 1];
//    fill(&dp[0][0], &dp[alp_req + 1][cop_req + 1], 1000000000);
    vector<vector<int>> dp(alp_req + 1, vector<int>(cop_req + 1, 1000000000));

    if (alp > alp_req) alp = alp_req;
    if (cop > cop_req) cop = cop_req;
    dp[alp][cop] = 0;

    for (int i = alp; i <= alp_req; i++) {
        for (int j = cop; j <= cop_req; j++) {
            if (j + 1 <= cop_req) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            if (i + 1 <= alp_req) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            for (auto &problem: problems) {
                if (i >= problem[0] && j >= problem[1]) {
                    dp[min(i + problem[2], alp_req)][min(j + problem[3], cop_req)] = min(
                            dp[min(i + problem[2], alp_req)][min(j + problem[3], cop_req)],
                            dp[i][j] + problem[4]);
                }
            }
        }
    }

    answer = dp[alp_req][cop_req];
    return answer;
}

int main() {
    int alp = 1;
    int cop = 1;
    vector<vector<int>> problems = {{1, 1},
                                    {2, 2}};
    int ret = solution(alp, cop, problems);

    printf("%d\n", ret);
}