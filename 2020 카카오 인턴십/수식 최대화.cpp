#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> ops;

    string num = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            nums.push_back(stoll(num));
            num = "";
            ops.push_back(expression[i]);
        } else {
            num += expression[i];
        }
    }
    nums.push_back(stoll(num));

    vector<char> op_order = {'*', '+', '-'};

    do {
        vector<long long> nums_copy = nums;
        vector<char> ops_copy = ops;

        for (int i = 0; i < op_order.size(); i++) {
            for (int j = 0; j < ops_copy.size(); j++) {
                if (ops_copy[j] == op_order[i]) {
                    if (op_order[i] == '+') {
                        nums_copy[j] += nums_copy[j + 1];
                    } else if (op_order[i] == '-') {
                        nums_copy[j] -= nums_copy[j + 1];
                    } else if (op_order[i] == '*') {
                        nums_copy[j] *= nums_copy[j + 1];
                    }
                    nums_copy.erase(nums_copy.begin() + j + 1);
                    ops_copy.erase(ops_copy.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(nums_copy[0])) answer = abs(nums_copy[0]);
    } while (next_permutation(op_order.begin(), op_order.end()));

    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    long long ret = solution(expression);

    printf("%lld\n", ret);
}