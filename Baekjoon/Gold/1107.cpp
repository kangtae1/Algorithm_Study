#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    bool broken[10] = {false, };
    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        broken[button] = true;
    }

    int min = abs(N - 100); // 전부 +나 -로만 이동하는 경우

    for (int i = 0; i < 1000000; i++) { // 0부터 1000000까지 모든 채널을 확인
        int count = 0; // 숫자 버튼을 누르는 횟수
        int temp = i;

        bool flag = true; // 고장난 버튼이 포함되어 있는지 확인
        if (temp == 0) {
            if (broken[temp]) {
                flag = false;
            } else {
                count++;
            }
        }
        while (temp > 0) { // 고장난 버튼이 포함되어 있으면 flag를 false로 바꾸고 break
            if (broken[temp % 10]) {
                flag = false;
                break;
            }
            count++; // 고장난 버튼이 포함되어 있지 않으면 count를 증가
            temp /= 10; // 다음 자리수로 이동
        }
        if (flag) {
            int press = abs(N - i); // 숫자 버튼을 누른 후 +나 -로 이동하는 횟수
            if (min > count + press) {
                min = count + press;
            }
        }
    }

    cout << min << endl;
    return 0;
}