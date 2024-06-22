#include <iostream>
#include <vector>

using namespace std;

void precomputeFibonacciCounts(vector<int>& count0, vector<int>& count1, int maxN) {
    // 초기값 설정
    count0[0] = 1;
    count1[0] = 0;
    count0[1] = 0;
    count1[1] = 1;

    // 피보나치 수열의 0과 1의 출력 횟수 계산
    for (int i = 2; i <= maxN; ++i) {
        count0[i] = count0[i - 1] + count0[i - 2];
        count1[i] = count1[i - 1] + count1[i - 2];
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> inputs(T);
    int maxN = 0;
    for (int i = 0; i < T; ++i) {
        cin >> inputs[i];
        maxN = max(maxN, inputs[i]);
    }

    // 최대 N까지의 피보나치 수열에서 0과 1의 출력 횟수를 미리 계산
    vector<int> count0(maxN + 1, 0);
    vector<int> count1(maxN + 1, 0);
    precomputeFibonacciCounts(count0, count1, maxN);

    // 각 테스트 케이스에 대해 결과 출력
    for (int i = 0; i < T; ++i) {
        int n = inputs[i];
        cout << count0[n] << " " << count1[n] << endl;
    }

    return 0;
}