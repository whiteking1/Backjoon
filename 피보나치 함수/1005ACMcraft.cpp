#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> buildTime(N + 1);
        vector<int> inDegree(N + 1, 0);
        vector<int> totalTime(N + 1, 0);
        vector<vector<int>> graph(N + 1);

        for (int i = 1; i <= N; ++i) {
            cin >> buildTime[i];
        }

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            inDegree[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;

        // ���� ������ 0�� ���(�ǹ�)���� ť�� �־��ش�
        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                totalTime[i] = buildTime[i];
            }
        }

        // ���� ������ �ϸ鼭 �ּ� �ð� ���
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                // ���� ������ ���̰�, �ش� �ǹ��� ���� �ּ� �ð��� ����Ѵ�
                inDegree[next]--;
                totalTime[next] = max(totalTime[next], totalTime[cur] + buildTime[next]);

                // ���� ������ 0�� �Ǹ� ť�� �־��ش�
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // ��� ���
        cout << totalTime[W] << "\n";
    }

    return 0;
}